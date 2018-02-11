#include <iostream>
#include <cstdio>
using namespace std;
int dp[505][505],a[505],b[505],prex[505][505],prey[505][505];
void print_ans(int x,int y){
	if(dp[x][y]==0)    return;
    int xx=prex[x][y];
    int yy=prey[x][y];
    print_ans(xx,yy);
    if(dp[x][y]!=dp[xx][yy] && y!=0){
        printf("%d",b[y]);
		printf(" ");
    }
}
int main(){
    int n,m;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i]!=a[j]) {
            	dp[i][j]=dp[i-1][j];
            	prex[i][j]=i-1;
            	prey[i][j]=j;
            }
            else {
            	int maxn=0;
            	int y=0;
                for (int k=1;k<=j;k++){
                    if (a[k]<a[j] && dp[i-1][k]>=maxn) maxn=dp[i-1][k]+1,y=k;
                }
                prex[i][j]=i-1;
                prey[i][j]=y;
                dp[i][j]=maxn;
            }
        }
    }
    int ans=0,fl=0;
    for (int i=1;i<=m;i++) if (dp[n][i]>ans) ans=dp[n][i],fl=i;
    cout<<ans<<endl;
    print_ans(n,fl);
}    
