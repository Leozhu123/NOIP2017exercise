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
const int maxn = 3006;
const int P = 64123;
LL dp[maxn][maxn];
int ok[maxn];
int g[maxn];
int siz[maxn];
int n,k,W;
int d[maxn];
vector<int> G[maxn];

void dfs(int x,int f){
    siz[x]=ok[x];
    for (int i = 0; i <= k;i++)
        dp[x][i] = 0;
    dp[x][ok[x]] = 1;
    for (int i = 0; i < G[x].size(); i++)
    {
        int v = G[x][i];
        if (v == f)
            continue;
        dfs(v, x);
        for (int j = siz[x]; j >= 0; j--)
        {
            int tmp = dp[x][j];
            for (int jj = siz[v]; jj >= 0; jj--)
            {
                dp[x][min(j + jj, k)] = (dp[x][min(j + jj, k)] + tmp * dp[v][jj]) % P;
            }
        }
        siz[x] = min(k, siz[x] + siz[v]);
    }
}
int main(){
    read(n, k, W);
    for (int i = 1;i<=n;i++)
        read(d[i]);
    for (int i = 1;i<=n-1;i++){
        int x,y;
        read(x,y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    LL ans = 0;
    for(int w=1;w<=W;w++){
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt += (ok[i] = (d[i] >= w));
        if(cnt<k)
            break;
        dfs(1, 0);
        for(int i=1;i<=n;i++)
            ans = (ans + dp[i][k]) % P;
    }
    cout << ans;
}