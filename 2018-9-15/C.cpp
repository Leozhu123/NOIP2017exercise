#include <iostream>
#include <vector>
#define P pair<int, int>
using namespace std;
struct Edge
{
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int maxn = 1005;
vector<Edge> G[maxn];
int fa[maxn][30];
int dis[maxn];
int dep[maxn];
P plan[maxn];
int s[maxn], e[maxn];
int calc_lca(int a, int b)
{
    if (dep[a] < dep[b])
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int delta = dep[a] - dep[b];
    for (int i = 0; i <= 25; i++)
    {
        if (delta & (1 << i))
            a = fa[a][i];
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 25; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}
void build_tree(int x, int f)
{
    fa[x][0] = f;
    for (int i = 1; i <= 25; i++)
    {
        if (fa[x][i - 1])
            fa[x][i] = fa[fa[x][i - 1]][i - 1];
        else
            break;
    }
    for (int i = 0; i < G[x].size(); i++)
    {
        Edge &e = G[x][i];
        if (e.v == f)
            continue;
        dis[e.v] = dis[x] + e.c;
        dep[e.v] = dep[x] + 1;
        build_tree(e.v, x);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back(Edge(u, v, c));
        G[v].push_back(Edge(v, u, c));
    }
    build_tree(1, 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i] >> e[i];
    }
    int ans = 1000000000;
    for (int c = 1; c <= n; c++)
    {
        int ma = 0;
        for(int i=1;i<=m;i++){
            ma = max(ma, dis[s[i]] + dis[e[i]] - 2 * dis[calc_lca(s[i], e[i])]);
        }
        ans = min(ans, ma);
    }
    cout << ans;
}