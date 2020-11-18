# 建立自己的邮箱服务器

### 0 序言

相信大家都会有自己的邮箱，但自己建立一个邮箱，使用自己的域名，岂不是更加炫酷。

### 1 准备工作

首先，你需要有自己的VPS，这依据大家喜好购买，邮件服务器对于VPS的配置要求不高512RAM+10G就可以了。

我使用的操作系统是Ubuntu16.04。

其次，你需要买一个自己的域名，这部分不再赘述。

### 2 设置DNS

进入你的DNS管理界面，如下表设置。

在下面的所有教程中，用你的域名代替oier.moe。

| 名称     | 值      | 类型 |
| -------- | :------ | ---- |
|oier.moe| your_ip | A    |
|mail.oier.moe| your_ip | A    |
|oier.moe|mail.oier.moe|MX|

### 3 安装必要软件

```bash
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository universe
sudo add-apt-repository ppa:certbot/certbot
sudo apt update
sudo apt install certbot
sudo apt install vim git 
sudo apt install postfix postfix-mysql dovecot-core dovecot-imapd dovecot-pop3d dovecot-lmtpd dovecot-mysql mysql-server
```

其中需要填写MySQL密码，安装postfix时选择Internet Site，然后mail name填入你的域名。

### 4 生成证书

我们要使用SSL保护服务器通信，就要生成一个证书。

```bash
sudo certbot certonly
```

根据提示输入1，你的邮箱，你的域名

### 5 更改hosts

```bash
sudo vim /etc/hosts
```

添加 

```hosts
your_ip mail.oier.moe oier.moe
```

### 6 设置SQL

运行

```bash
sudo mysql_secure_installation #密码强度随意，其余全部选Y
sudo mysqladmin -u root -p create mailserver#创建新的数据库
sudo mysql -u root -p#登录数据库
```



```mysql
GRANT SELECT ON mailserver.* TO 'mailuser'@'127.0.0.1' IDENTIFIED BY 'mailuserpass';#添加新的用户，mailuserpass改为安全密码
FLUSH PRIVILEGES;
USE mailserver;

CREATE TABLE `virtual_domains` (
  `id` int(11) NOT NULL auto_increment,
  `name` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `virtual_users` (
  `id` int(11) NOT NULL auto_increment,
  `domain_id` int(11) NOT NULL,
  `password` varchar(106) NOT NULL,
  `email` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`),
  FOREIGN KEY (domain_id) REFERENCES virtual_domains(id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `virtual_aliases` (
  `id` int(11) NOT NULL auto_increment,
  `domain_id` int(11) NOT NULL,
  `source` varchar(100) NOT NULL,
  `destination` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  FOREIGN KEY (domain_id) REFERENCES virtual_domains(id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8; # 建立三个表，直接复制就行了 
```

然后添加一点数据

```mysql
insert into virtual_domains (name) values
('oier.moe'),('mail.oier.moe');
insert into virtual_users (domain_id,password, email) values
('1',ENCRYPT('password', CONCAT('$6$', SUBSTRING(SHA(RAND()), -16))),'ciwomuli@oier.moe');# 请自行更改密码和用户名，直接用这条语句添加新的用户。
quit;#退出
```

### 6 配置postfix

```bash
sudo cp /etc/postfix/main.cf /etc/postfix/main.cf.orig #备份
sudo vim /etc/postfix/main.cf
```

修改为一下内容

```bash
smtpd_banner = $myhostname ESMTP $mail_name (Ubuntu)
biff = no

append_dot_mydomain = no

#delay_warning_time = 4h

readme_directory = no

smtpd_tls_cert_file=/etc/letsencrypt/live/oier.moe/fullchain.pem #改为你的域名
smtpd_tls_key_file=/etc/letsencrypt/live/oier.moe/privkey.pem #改为你的域名
smtpd_use_tls=yes
smtpd_tls_auth_only = yes
smtp_tls_security_level = may
smtpd_tls_security_level = may
smtpd_sasl_security_options = noanonymous, noplaintext
smtpd_sasl_tls_security_options = noanonymous

smtpd_sasl_type = dovecot
smtpd_sasl_path = private/auth
smtpd_sasl_auth_enable = yes

smtpd_helo_restrictions =
        permit_mynetworks,
        permit_sasl_authenticated,
        reject_invalid_helo_hostname,
        reject_non_fqdn_helo_hostname
smtpd_recipient_restrictions =
        permit_mynetworks,
        permit_sasl_authenticated,
        reject_non_fqdn_recipient,
        reject_unknown_recipient_domain,
        reject_unlisted_recipient,
        reject_unauth_destination
smtpd_sender_restrictions =
        permit_mynetworks,
        permit_sasl_authenticated,
        reject_non_fqdn_sender,
        reject_unknown_sender_domain
smtpd_relay_restrictions =
        permit_mynetworks,
        permit_sasl_authenticated,
        defer_unauth_destination

myhostname = oier.moe #改为你的域名
alias_maps = hash:/etc/aliases
alias_database = hash:/etc/aliases
mydomain = oier.moe #改为你的域名
myorigin = $mydomain
mydestination = localhost
relayhost =
mynetworks = 127.0.0.0/8 [::ffff:127.0.0.0]/104 [::1]/128
mailbox_size_limit = 0
recipient_delimiter = +
inet_interfaces = all
inet_protocols = all

virtual_transport = lmtp:unix:private/dovecot-lmtp

virtual_mailbox_domains = mysql:/etc/postfix/mysql-virtual-mailbox-domains.cf
virtual_mailbox_maps = mysql:/etc/postfix/mysql-virtual-mailbox-maps.cf
virtual_alias_maps = mysql:/etc/postfix/mysql-virtual-alias-maps.cf,
        mysql:/etc/postfix/mysql-virtual-email2email.cf

disable_vrfy_command = yes
strict_rfc821_envelopes = yes
smtpd_delay_reject = yes
smtpd_helo_required = yes
smtp_always_send_ehlo = yes
smtpd_timeout = 30s
smtp_helo_timeout = 15s
smtp_rcpt_timeout = 15s
smtpd_recipient_limit = 40
minimal_backoff_time = 180s
maximal_backoff_time = 3h

invalid_hostname_reject_code = 550
non_fqdn_reject_code = 550
unknown_address_reject_code = 550
unknown_client_reject_code = 550
unknown_hostname_reject_code = 550
unverified_recipient_reject_code = 550
unverified_sender_reject_code = 550
```

配置postfix-sql

```bash
# 创建 /etc/postfix/mysql-virtual-mailbox-domains.cf
user = mailuser
password = mailuserpass
hosts = 127.0.0.1
dbname = mailserver
query = SELECT 1 FROM virtual_domains WHERE name='%s'
# /etc/postfix/mysql-virtual-mailbox-maps.cf
user = mailuser
password = mailuserpass
hosts = 127.0.0.1
dbname = mailserver
query = SELECT 1 FROM virtual_users WHERE email='%s'
# /etc/postfix/mysql-virtual-alias-maps.cf
user = mailuser
password = mailuserpass
hosts = 127.0.0.1
dbname = mailserver
query = SELECT destination FROM virtual_aliases WHERE source='%s'
# /etc/postfix/mysql-virtual-email2email.cf
user = mailuser
password = mailuserpass
hosts = 127.0.0.1
dbname = mailserver
query = SELECT email FROM virtual_users WHERE email='%s'
# 所有的密码改为自己设定的
```
然后运行
```bash
sudo systemctl restart postfix # 重启一下
```

```bash
# 修改 /etc/postfix/master.cf，记得备份
#去掉以下内容的注释
smtp      inet  n       -       n       -       -       smtpd

submission inet n       -       y      -       -       smtpd
  -o syslog_name=postfix/submission
  -o smtpd_tls_security_level=encrypt
  -o smtpd_sasl_auth_enable=yes
  -o smtpd_sasl_type=dovecot
  -o smtpd_sasl_path=private/auth
  -o smtpd_reject_unlisted_recipient=no
  -o smtpd_client_restrictions=permit_sasl_authenticated,reject
  -o milter_macro_daemon_name=ORIGINATING
smtps     inet  n       -       -       -       -       smtpd
  -o syslog_name=postfix/smtps
  -o smtpd_tls_wrappermode=yes
  -o smtpd_sasl_auth_enable=yes
  -o smtpd_sasl_type=dovecot
  -o smtpd_sasl_path=private/auth
  -o smtpd_client_restrictions=permit_sasl_authenticated,reject
  -o milter_macro_daemon_name=ORIGINATING
```

```bash
sudo chmod -R o-rwx /etc/postfix # 修改权限
sudo systemctl restart postfix # 重启
```

### 7 配置dovecot

好了，你已经配置完了postfix，还剩dovecot要配置

```bash
#修改 /etc/dovecot/dovecot.conf
#加入
!include_try /usr/share/dovecot/protocols.d/*.protocol
protocols = imap pop3 lmtp

postmaster_address=postmaster at oier.moe

#修改 /etc/dovecot/conf.d/10-mail.conf
#加入
mail_location = maildir:/var/mail/vhosts/%d/%n/
mail_privileged_group = mail

#bash
sudo mkdir -p /var/mail/vhosts/example.com #创建邮箱目录
sudo groupadd -g 5000 vmail
sudo useradd -g vmail -u 5000 vmail -d /var/mail 
sudo chown -R vmail:vmail /var/mail # 建立用户并赋予权限
#修改 /etc/dovecot/conf.d/10-auth.conf
disable_plaintext_auth = yes
auth_mechanisms = plain login
!include auth-system.conf.ext
!include auth-sql.conf.ext
#修改 /etc/dovecot/conf.d/auth-sql.conf.ext
userdb {
  driver = static
  args = uid=vmail gid=vmail home=/var/mail/vhosts/%d/%n
}
#修改 /etc/dovecot/dovecot-sql.conf.ext
driver = mysql

connect = host=127.0.0.1 dbname=mailserver user=mailuser password=mailuserpass

default_pass_scheme = SHA512-CRYPT

password_query = SELECT email as user, password FROM virtual_users WHERE email='%u';
#bash
sudo chown -R vmail:dovecot /etc/dovecot
sudo chmod -R o-rwx /etc/dovecot # 添加权限

#修改 /etc/dovecot/conf.d/10-master.conf
service imap-login {
  inet_listener imap {
    port = 0
  }
  inet_listener imaps {
    port = 993
    ssl = yes
  }
}

service pop3-login {
  inet_listener pop3 {
    port = 0
  }
  inet_listener pop3s {
    port = 995
    ssl = yes
  }
}

service lmtp {
  unix_listener /var/spool/postfix/private/dovecot-lmtp {
    #mode = 0666i
    mode = 0600
    user = postfix
    group = postfix
  }
}

service auth {
  unix_listener /var/spool/postfix/private/auth {
    mode = 0660
    user = postfix
    group = postfix
  }

  unix_listener auth-userdb {
    mode = 0600
    user = vmail
  }
  user = dovecot
}

service auth-worker {
  user = vmail
}
# 修改 /etc/dovecot/conf.d/10-ssl.conf
ssl = required
ssl_cert = </etc/letsencrypt/live/oier.moe/fullchain.pem
ssl_key = </etc/letsencrypt/live/oier.moe/privkey.pem
#bash
sudo systemctl restart dovecot # 重启一下
```
### 8 其他
腾讯云可能要申请解封25号端口
如果有问题可以私信我