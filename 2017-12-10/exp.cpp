#include<iostream>
#include<cstring>
#include<cstdio>
#define p0 f[topn][0]
#define p1 f[topn][1]
#define q0 f[topn-1][0]
#define q1 f[topn-1][1]
#define ot o[topo]
#define maxn 100010
#define bp 10007//上面的东西都是为了方便，比较懒23333
using namespace std;
int f[maxn][2];//数字栈
char o[maxn];//符号栈
int topn=0,topo=0;//栈顶
void pushn()//压数字的程序
{
    topn++;
    p0=p1=1;
}
void pusho(char a)//压符号的程序
{
    topo++;
    ot=a;
}
void calc()//计算
{
    int t0,t1;
    if(ot=='+')
    {
        t0=(p0*q0)%bp;
        t1=(p0*q1)%bp+(p1*q0)%bp+(p1*q1)%bp;
    }
    else
    {
        t0=(p0*q1)%bp+(p1*q0)%bp+(q0*p0)%bp;
        t1=(p1*q1)%bp;
    }
    topo--;
    topn--;
    p0=t0;
    p1=t1;
}//全是公式，记得要用变量存，直接改变可能会导致引用错误
int main()
{
    int l;
    string s;
    scanf("%d",&l);
    cin>>s;
    s='('+s+')';
    for(int i=0;i<s.length();i++)
      switch(s[i])
      {
          case '(':{
              pusho(s[i]);//如果是左括号就直接压栈
              if(s[i+1]!='(')pushn();//两个左括号的话中间不能放数哦
            break;
          }
        case ')':{
            while(ot!='(')calc();//右括号的话就直接一直计算直到有左括号
            topo--;
            break;
        }
        case '+':{
            while(ot!='(')calc();//加法的话就可以直接计算到左括号，因为优先级最低
            pusho(s[i]);
            if(s[i+1]!='(')pushn();
            break;
        }
        case '*':{
            while(ot=='*')calc();//乘号的话就只能计算优先级相同的符号
            pusho(s[i]);
            if(s[i+1]!='(')pushn();
            break;
        }
      }
      printf("%d\n",p0%10007);//结果别忘了取模
      return 0;
}
