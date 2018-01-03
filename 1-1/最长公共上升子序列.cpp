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
void out(int x,int y)    //递归输出路径、 
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
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);        //先更新状态，如果后面会更新的话再去更新 
            prex[i][j]=i-1;
            prey[i][j]=j;
            if(a[i]>b[j] && maxn<dp[i-1][j]){    //我开始一直没想通为什么要在a[i]>b[j]的时候才更新值 
                maxn=dp[i-1][j];// 其实你想想dp[i][j]中i,j都有什么含义、 
                x=i-1;        // 这个if里面更新出来的maxn只有在满足a[i]==b[j]的时候才有用、 
                y=j;    //  这里更新出来的值就是为了保证当a[i]==b[j]的时候 
            }            //所更新出来的最大值是一个递增的子序列、 
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
}//网址http://poj.org/problem?id=2127 
