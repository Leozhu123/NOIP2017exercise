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
#include <regex>
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

const int maxn=1e5 + 5;
const int P = 1e9 + 7;
int dp[maxn][105][2][2];
int g[105][2][2];
int siz[maxn];
int n, m, k;
inline int add(int x, long long y) {
    if (y >= P) y %= P;
    for (x += y; x >= P; x -= P);
    return x;
}
vector<int> G[maxn];
void dfs(int u,int f){
    siz[u] = 1;
    dp[u][0][0][0] = 1;
    dp[u][1][1][0] = 1;
    for (int i = 0; i < G[u].size();i++){
        int v = G[u][i];
        if(v==f)
            continue;
        dfs(v, u);
        for (int i = 0; i <= min(siz[u], k);i++){
            g[i][0][0] = dp[u][i][0][0], dp[u][i][0][0] = 0;
            g[i][0][1] = dp[u][i][0][1], dp[u][i][0][1] = 0;
            g[i][1][0] = dp[u][i][1][0], dp[u][i][1][0] = 0;
            g[i][1][1] = dp[u][i][1][1], dp[u][i][1][1] = 0;
        }
        for (int i = 0; i <= min(siz[u], k);i++){
            for (int j = 0; j <= min(siz[v], k - i);j++){
                dp[u][i + j][0][0] = add(dp[u][i + j][0][0], 1ll * g[i][0][0] * dp[v][j][0][1]);
                dp[u][i + j][0][1] = add(dp[u][i + j][0][1], 1ll * g[i][0][1] * (dp[v][j][0][1] + dp[v][j][1][1]));
                dp[u][i + j][0][1] = add(dp[u][i + j][0][1], 1ll * g[i][0][0] * dp[v][j][1][1]);
                dp[u][i + j][1][0] = add(dp[u][i + j][1][0], 1ll * g[i][1][0] * (dp[v][j][0][0] + dp[v][j][0][1]));
                dp[u][i + j][1][1] = add(dp[u][i + j][1][1], 1ll * g[i][1][0] * (dp[v][j][1][0] + dp[v][j][1][1]));
                dp[u][i + j][1][1] = add(dp[u][i + j][1][1], 1ll * g[i][1][1] * (1ll * dp[v][j][0][0] + dp[v][j][0][1] + 1ll * dp[v][j][1][0] + dp[v][j][1][1]));
            }
        }
        siz[u] += siz[v];
    }
}
int main(){
    read(n, k);
    for (int i = 1; i < n;i++){
        int u,v;
        read(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1][k][0][1] + dp[1][k][1][1]) % P;
}