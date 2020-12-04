//by ciwomuli
//enter ICPC WF 2020
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
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
const int maxn = 2e5 + 5;
int n, t;
int cnt[maxn];
int G[maxn][3];
int dep[maxn];
int sizehuan, sizelian;
void dfs(int x, int fa)
{
    for (int i = 0; i < cnt[x]; i++)
    {
        int v = G[x][i];
        if (v == fa)
            continue;
        if (dep[v])
        {
            sizehuan = dep[v] - dep[x] + 1;
            return;
        }
        dep[v] = dep[x] + 1;
        dfs(v, x);
    }
}
int main()
{
    int t;
    read(t);
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(G, 0, sizeof(G));
        memset(dep, 0, sizeof(dep));
        read(n);
        for (int i = 1; i <= n; i++)
        {
            int u, v;
            read(u, v);
            G[u][cnt[u]++] = v;
            G[v][cnt[v]++] = u;
        }
        int S = 1;
        for (int i = 1; i <= n; i++)
            if (cnt[i] == 1)
                S = i;
        dep[S] = 1;
        cout << S << endl;
        dfs(S, 0);
        cout << sizehuan << endl;
        sizelian = n - sizehuan;
        cout << sizehuan * (sizehuan - 1) + sizelian * (sizelian - 1) / 2 + sizelian * (2 * sizehuan - 1) << endl;
    }
}