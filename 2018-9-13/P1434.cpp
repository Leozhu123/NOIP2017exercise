#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=105;
const int addx[4]={1,0,-1,0};
const int addy[4]={0,-1,0,1};
const int inf=(1<<31)-1;
int dp[maxn][maxn];
int h[maxn][maxn];
int r,c;
int dfs(int x,int y){
    if(dp[x][y]>0) return dp[x][y];
    dp[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+addx[i];
        int ty=y+addy[i];
        if(tx>r || tx<1 || ty>c || ty<1) continue;
        if(h[tx][ty]>=h[x][y]) continue;
        dp[x][y]=max(dp[x][y],dfs(tx,ty)+1);
    }
    return dp[x][y];
}
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            dp[i][j]=-1;
            cin>>h[i][j];
        }
    }
    int ans=1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans;
}
