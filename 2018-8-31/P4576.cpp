#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n, r1, c1, r2, c2;
int dp[2][60][25][25][25][25];
const int inf = 1e9 + 7;
int abs(int x){
    return x > 0 ? x : -x;
}
int dfs(int player,int dep,int r1,int c1,int r2,int c2){
    int ans;
    if(dep>3*n)
        return inf;
    if(dp[player][dep][r1][c1][r2][c2])
        return dp[player][dep][r1][c1][r2][c2];
    if(r1==r2 && c1==c2){
        return player? inf : 0;
    }
    if(!player){
        ans = 0;
        if(r1>1) ans = max(ans, dfs(1, dep+1, r1-1, c1, r2, c2));
        if(r1<n) ans = max(ans, dfs(1, dep+1, r1+1, c1, r2, c2));
        if(c1>1) ans = max(ans, dfs(1, dep+1, r1, c1-1, r2, c2));
        if(c1<n) ans = max(ans, dfs(1, dep+1, r1, c1+1, r2, c2));
    }else{
        ans = inf;
        if(r2>1) ans = min(ans, dfs(0, dep+1, r1, c1, r2-1, c2));
        if(r2>2) ans = min(ans, dfs(0, dep+1, r1,c1, r2-2, c2));
        if(r2<n) ans = min(ans, dfs(0, dep+1, r1, c1, r2+1, c2));
        if(r2<n-1) ans = min(ans, dfs(0, dep+1, r1, c1, r2+2, c2));
        if(c2>1) ans = min(ans, dfs(0, dep+1, r1, c1, r2, c2-1));
        if(c2>2) ans = min(ans, dfs(0, dep+1, r1, c1, r2, c2-2));
        if(c2<n) ans = min(ans, dfs(0, dep+1, r1, c1, r2, c2+1));
        if(c2<n-1) ans = min(ans, dfs(0, dep+1, r1, c1, r2, c2+2));
    }
   // cout << ans+1 << endl;
    dp[player][dep][r1][c1][r2][c2] = ++ans;
    return ans;
}
int main(){
    cin >> n >> r1 >> c1 >> r2 >> c2;
    if(abs(r1-r2)+abs(c1-c2)<=1){
        puts("WHITE 1\n");
    }
    else{
        printf("BLACK %d\n", dfs(0, 0, r1, c1, r2, c2));
    }
    return 0;
}