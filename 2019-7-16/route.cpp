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
struct Edge
{
    int u, v, p, q;
    Edge(int u, int v, int p, int q) : u(u), v(v), p(p), q(q) {}
};
int n, m, A, B, C;
const int maxn = 1e5 + 5;
int wyt = 0;
unsigned int f[maxn][1005];
vector<Edge> G[maxn];
vector<Edge> rG[maxn];
vector<int> time[maxn];
unsigned int dp(int x, int t)
{
    if (f[x][t] < INT_MAX)
        return f[x][t];
    for (int i = 0; i < rG[x].size(); i++)
    {
        Edge &e = rG[x][i];
        if (e.q != t)
            continue;
        if (e.u == 1)
        {
            f[x][t] = A * e.p * e.p + B * e.p + C + t;
            return f[x][t];
        }
        for(int j:time[e.u])
        {
            if(j > e.p)
                break;
            f[x][t] = min(f[x][t],
                          dp(e.u, j) + A * (e.p - j) * (e.p - j) + B * (e.p - j) + C + t - j);
        }
    }
    return f[x][t];
}
int main()
{
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
    read(n, m, A, B, C);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 1000; j++)
            f[i][j] = INT_MAX;
    f[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, p, q;
        read(u, v, p, q);
        G[u].push_back(Edge(u, v, p, q));
        rG[v].push_back(Edge(u, v, p, q));
        time[u].push_back(p);time[u].push_back(q);
        time[v].push_back(p);time[v].push_back(q);
    }
    unsigned int ans = INT_MAX;
    for (int i = 0; i <= 1000; i++)
    {
        ans = min(ans, dp(n, i));
    }
    cout << ans;
}