#include <cctype>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define LL long long
const int maxn = 10005;
const int inf = 1000000001;
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
using namespace std;
struct Edge
{
    int u, v;
    LL b;
    Edge(int u, int v, LL b) : u(u), v(v), b(b) {}
};
vector<Edge> G[maxn];
bool inq[maxn];
LL dis[maxn];
LL cost[maxn];
void init()
{
    memset(inq, 0, sizeof(inq));
    for (int i = 0; i < maxn; i++)
    {
        dis[i] = INT_MAX;
    }
}
int n, m, b;
bool check(LL mid)
{
    if(cost[1]>mid)
        return false;
    init();
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    inq[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        inq[x] = 0;
        for (int i = 0; i < G[x].size(); i++)
        {
            Edge &e = G[x][i];
            if (cost[e.v] > mid)
                continue;
            if (dis[e.v] > dis[x] + e.b)
            {
                dis[e.v] = dis[x] + e.b;
                if (!inq[e.v])
                {
                    q.push(e.v);
                    inq[e.v] = 1;
                }
            }
        }
    }
    return dis[n] < b;
}
int main()
{
    LL l = 0, r = 0;
    read(n, m, b);
    for (int i = 1; i <= n; i++)
        read(cost[i]), r = max(r, cost[i]);
    l = min(cost[1], cost[n]);
    for (int i = 1; i <= m; i++)
    {
        LL a, b, c;
        read(a, b, c);
        G[a].push_back(Edge(a, b, c));
        G[b].push_back(Edge(b, a, c));
    }
    while (l + 5 < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (check(i))
        {
            ans = i;
            break;
        }
    }
    if (!check(inf))
        cout << "AFK";
    else
        cout << ans;
}
