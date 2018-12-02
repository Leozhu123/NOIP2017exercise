
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
const int MAXN=1e6,MAXNODE=MAXN*2+MAXN/10;
int num[MAXN],n,m;
void Read(int& x)
{
    x=0;int flag=0;char c=0;
    while(c=getchar())
    {
        if(c>='0'&&c<='9')x*=10,x+=c-'0',flag=1;
        else if(flag)break;
    }
}
struct SegMentTree{
    int tag[MAXNODE],minv[MAXNODE];
    void Build(const int& now,const int& l,const int& r)
    {
        tag[now]=0;
        if(l==r)
        {
            minv[now]=num[l];
            return;
        }
        int mid=(l+r)>>1;
        if(l<=mid) Build(now<<1,l,mid);
        if(r>mid)  Build(now<<1|1,mid+1,r);
        minv[now]=std::min(minv[now<<1],minv[now<<1|1]);
    }
    void push_down(const int &now)
    {
        if(tag[now])
        {
            tag[now<<1]+=tag[now];
            tag[now<<1|1]+=tag[now];
            minv[now<<1]+=tag[now];
            minv[now<<1|1]+=tag[now];
            tag[now]=0;
        }
    }
    void add(const int& now,const int& l,const int& r,const int& ql,const int& qr,const int& v)
    {
        if(qr>=r&&ql<=l)
        {
            tag[now]+=v;
            minv[now]+=v;
            return ;
        }
        push_down(now);
        int mid=(l+r)>>1;
        if(ql<=mid)add(now<<1,l,mid,ql,qr,v);
        if(qr>mid)add(now<<1|1,mid+1,r,ql,qr,v);
        minv[now]=std::min(minv[now<<1],minv[now<<1|1]);
    }
    int query(const int& now,const int& l,const int& r,const int& ql,const int& qr)
    {
        if(qr>=r&&ql<=l)
        {
            return minv[now];
        }
        push_down(now);
        int mid=(l+r)>>1,ans=0x7fffffff;
        if(ql<=mid)ans=std::min(ans,query(now<<1,l,mid,ql,qr));
        if(qr>mid)ans=std::min(ans,query(now<<1|1,mid+1,r,ql,qr));
        minv[now]=std::min(minv[now<<1],minv[now<<1|1]);
        return ans;
    }
}Tree;
int main()
{
	 freopen("classroom.in", "r", stdin);
    freopen("classroom.out", "w", stdout);
    Read(n);Read(m);
    for(int i=1;i<=n;i++)Read(num[i]);
    Tree.Build(1,1,n);
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
        Read(a);Read(b);Read(c);
        int res=Tree.query(1,1,n,b,c);
        if(res<a)
        {
            printf("-1\n%d",i);
            return 0;
        }
        else
            Tree.add(1,1,n,b,c,-a);
    }
    printf("0");
    } 


