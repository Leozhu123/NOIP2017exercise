#include<iostream>
#include<cstring>
#include<cstdio>
#define p0 f[topn][0]
#define p1 f[topn][1]
#define q0 f[topn-1][0]
#define q1 f[topn-1][1]
#define ot o[topo]
#define maxn 100010
#define bp 10007//����Ķ�������Ϊ�˷��㣬�Ƚ���23333
using namespace std;
int f[maxn][2];//����ջ
char o[maxn];//����ջ
int topn=0,topo=0;//ջ��
void pushn()//ѹ���ֵĳ���
{
    topn++;
    p0=p1=1;
}
void pusho(char a)//ѹ���ŵĳ���
{
    topo++;
    ot=a;
}
void calc()//����
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
}//ȫ�ǹ�ʽ���ǵ�Ҫ�ñ����棬ֱ�Ӹı���ܻᵼ�����ô���
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
              pusho(s[i]);//����������ž�ֱ��ѹջ
              if(s[i+1]!='(')pushn();//���������ŵĻ��м䲻�ܷ���Ŷ
            break;
          }
        case ')':{
            while(ot!='(')calc();//�����ŵĻ���ֱ��һֱ����ֱ����������
            topo--;
            break;
        }
        case '+':{
            while(ot!='(')calc();//�ӷ��Ļ��Ϳ���ֱ�Ӽ��㵽�����ţ���Ϊ���ȼ����
            pusho(s[i]);
            if(s[i+1]!='(')pushn();
            break;
        }
        case '*':{
            while(ot=='*')calc();//�˺ŵĻ���ֻ�ܼ������ȼ���ͬ�ķ���
            pusho(s[i]);
            if(s[i+1]!='(')pushn();
            break;
        }
      }
      printf("%d\n",p0%10007);//���������ȡģ
      return 0;
}
