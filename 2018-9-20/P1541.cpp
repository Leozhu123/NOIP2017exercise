#include <iostream>
using namespace std;
int dp[50][50][50][50];
int n,m;
int g[5];
int num[400];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        g[x]++;
    }
    dp[0][0][0][0]=num[1];
    for(int i1=0;i1<=g[1];i1++){
        for(int i2=0;i2<=g[2];i2++){
            for(int i3=0;i3<=g[3];i3++){
                for(int i4=0;i4<=g[4];i4++){
                    int r=1+1*i1+2*i2+3*i3+4*i4;
                    if(i1) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1-1][i2][i3][i4]+num[r]);
                    if(i2) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1][i2-1][i3][i4]+num[r]);
                    if(i3) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1][i2][i3-1][i4]+num[r]);
                    if(i4) dp[i1][i2][i3][i4]=max(dp[i1][i2][i3][i4],dp[i1][i2][i3][i4-1]+num[r]);
                }
            }
        }
    }
    cout<<dp[g[1]][g[2]][g[3]][g[4]];
}