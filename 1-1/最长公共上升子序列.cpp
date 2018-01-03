#include<cmath>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
const int qq=505;
int a[qq],b[qq];
int dp[qq][qq];
int prex[qq][qq];
int prey[qq][qq];
int ans;
int count1;
void out(int x,int y)    //�ݹ����·���� 
{
    if(dp[x][y]==0)    return;
    int xx=prex[x][y];
    int yy=prey[x][y];
    out(xx,yy);
    if(dp[x][y]!=dp[xx][yy] && y!=0){
        printf("%d",b[y]);
        count1++;
        if(count1<ans)    printf(" ");
        else            printf("\n");
    }
}
int main()
{
    int t;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
        scanf("%d",&b[i]);
    memset(prex,-1,sizeof(prex));
    memset(prey,-1,sizeof(prey));
    memset(dp,0,sizeof(dp));
    for(int j,i=1;i<=n;++i){
        int maxn=0;
        int x,y;x=y=0;
        for(j=1;j<=m;++j){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);        //�ȸ���״̬������������µĻ���ȥ���� 
            prex[i][j]=i-1;
            prey[i][j]=j;
            if(a[i]>b[j] && maxn<dp[i-1][j]){    //�ҿ�ʼһֱû��ͨΪʲôҪ��a[i]>b[j]��ʱ��Ÿ���ֵ 
                maxn=dp[i-1][j];// ��ʵ������dp[i][j]��i,j����ʲô���塢 
                x=i-1;        // ���if������³�����maxnֻ��������a[i]==b[j]��ʱ������á� 
                y=j;    //  ������³�����ֵ����Ϊ�˱�֤��a[i]==b[j]��ʱ�� 
            }            //�����³��������ֵ��һ�������������С� 
            else if(a[i]==b[j]){
                dp[i][j]=maxn+1;
                prex[i][j]=x;
                prey[i][j]=y;
            }
        }
    }
    ans=0;
    int flag=-1;
    for(int i=1;i<=m;++i){
        if(ans<dp[n][i]){
            flag=i;
            ans=dp[n][i];
        }
    }
    printf("%d\n",ans);
    int x=n,y=flag;
    count1=0;
    if(ans>0)
        out(x,y);
    if(t)    printf("\n");
    return 0;
}//��ַhttp://poj.org/problem?id=2127 
