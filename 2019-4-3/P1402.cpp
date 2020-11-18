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
const int maxn = 10005;
struct Edge
{
    int from, to, cap, flow;
    Edge(int from, int to, int cap) : from(from), to(to), cap(cap), flow(0) {}
};
struct Dinic
{
    vector<Edge> edge;
    vector<int> G[maxn];
    int maxflow = 0;
    void addEdge(int from, int to, int cap)
    {
        Edge e1(from, to, cap);
        Edge e2(to, from, 0);
        edge.push_back(e1);
        edge.push_back(e2);
        int m = edge.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    int d[maxn], cur[maxn], s, t;
    bool vis[maxn];
    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        queue<int> q;
        q.push(s);
        d[s] = 1;
        vis[s] = true;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = edge[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    d[e.to] = d[x] + 1;
                    vis[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x, int a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++)
        {
            Edge &e = edge[G[x][i]];
            if (d[e.to] == d[x] + 1 && e.cap > e.flow && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
            {
                flow += f;
                e.flow += f;
                edge[G[x][i] ^ 1].flow -= f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int MaxFlow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int ans = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            ans += DFS(s, INT_MAX);
        }
        return ans;
    }
};
int main()
{
    int n, p, q;
    read(n, p, q);
    int s = 2 * n + p + q + 1;
    int t = s + 1;
    Dinic dinic;
    for (int i = 1; i <= n; i++)
    {
        dinic.addEdge(i, n + i, 1);
    }
    for (int i = 1; i <= p; i++)
    {
        dinic.addEdge(s, n * 2 + i, 1);
    }
    for (int i = 1; i <= q; i++)
    {
        dinic.addEdge(n * 2 + p + i, t, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            int x;
            read(x);
            if (x)
                dinic.addEdge(n * 2 + j, i, 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= q; j++)
        {
            int x;
            read(x);
            if (x)
                dinic.addEdge(n + i, n * 2 + p + j, 1);
        }
    }
    cout << dinic.MaxFlow(s, t);
}