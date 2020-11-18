//by ciwomuli
//AK JSOI 2019
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#define LL long long
using namespace std;
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
const int maxn = 305;
vector<int> G[maxn];
int dp[maxn][maxn];
int siz[maxn];
int n,m;
void dfs(int x,int f){
    siz[x] = 1;
    if(G[x].size() == 1){
        for (int i = 1; i <= m;i++)
                dp[x][i] = dp[x][1];
        return;
    }
    for (int i = 0; i < G[x].size();i++){
        int v=G[x][i];
        if(v==f) continue;
        dfs(v,x);
        siz[x] += siz[v];
        for (int j = m + 1; j > 0;j--){
            for (int k = 0; k < j;k++){
                if(j - k >= 0) dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[v][k]);
            }
        }
    }
}
int main(){
    read(n, m);
    for (int i = 1; i <= n;i++){
        int k;
        read(k,dp[i][1]);
        G[k].push_back(i);
        G[i].push_back(k);
    }
    dfs(0, -1);
    cout << dp[0][m];
}