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
const int maxn = 1e4 + 4;
struct Edge
{
    int u, v, c, f;
    Edge(int _u, int _v, int _c, int _f) : u(_u), v(_v), c(_c), f(_f) {}
};
namespace Dinic
{
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn];
    void ae(int u, int v, int f)
    {
        Edge e1(u, v, f, 0), e2(v, u, 0, 0);
        edges.push_back(e1);
        edges.push_back(e2);
        int s = edges.size();
        G[u].push_back(s - 2);
        G[v].push_back(s - 1);
    }
    int S, T;
    bool BFS()
    {
        memset(d, 0, sizeof(d));
        d[S] = 1;
        queue<int> q;
        q.push(S);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (!d[e.v] && e.c > e.f)
                {
                    d[e.v] = d[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[T];
    }
    int DFS(int u, int a)
    {
        int ans = 0;
        if (u == T || a <= 0)
            return a;
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge &e = edges[G[u][i]];
            int f = 0;
            if (d[e.v] == d[u] + 1 && e.c > e.f)
            {
                f = DFS(e.v, min(a, e.c - e.f));
                ans += f;
                e.f += f;
                a -= f;
                edges[G[u][i] ^ 1].f -= f;
                if (a == 0)
                    break;
            }
        }
        return ans;
    }
    int maxflow(int s, int t)
    {
        S = s, T = t;
        int flow = 0;
        while (BFS())
        {
            flow += DFS(S, INT_MAX);
        }
        return flow;
    }
}; // namespace Dinic
int map[55][55];
int n;
bool isred(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n)
        return true;
    return map[i][j] == 1;
}
int pos2num(int i, int j)
{
    return (i - 1) * n + j;
}
int main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'O')
                map[i][j] = 0;
            if (ch == 'X')
                map[i][j] = 1;
            if (ch == '.')
                map[i][j] = 2;
        }
    }
    int s = n * n + 1, t = n * n + 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 2)
            {
                Dinic::ae(s, pos2num(i, j), INT_MAX);
                Dinic::ae(pos2num(i, j), t, 1);
            }
            if (map[i][j] == 0)
            {
                Dinic::ae(pos2num(i, j), t, 1);
                vector<pair<int, int>> vec;
                if (isred(i - 1, j))
                    vec.push_back(pair<int, int>(i - 1, j));
                if (isred(i + 1, j))
                    vec.push_back(pair<int, int>(i + 1, j));
                if (isred(i, j - 1))
                    vec.push_back(pair<int, int>(i, j - 1));
                if (isred(i, j + 1))
                    vec.push_back(pair<int, int>(i, j + 1));
                
            }
        }
    }
}