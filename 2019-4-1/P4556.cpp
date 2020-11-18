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
const int maxn = 100005;
vector<int> G[maxn];
int rt[maxn];
int tot = 0;
int x[maxn * 6], lch[maxn * 6], rch[maxn * 6];
void upd(int o)
{
    x[o] = max(x[lch[o]], x[rch[o]]);
}
void modify(int &o, int l, int r, int p, int a)
{
    if (o == 0)
        o = ++tot;
    if (l == r)
    {
        x[o] += a;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
        modify(lch[o], l, mid, p, a);
    else
        modify(rch[o], mid + 1, r, p, a);
    upd(o);
}
int merge(int a, int b, int l, int r)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int o = ++tot;
    if (l == r)
    {
        x[o] = x[a] + x[b];
        return o;
    }
    int mid = (l + r) >> 1;
    lch[o] = merge(lch[a], lch[b], l, mid);
    rch[o] = merge(rch[a], rch[b], mid + 1, r);
    upd(o);
    return o;
}
int qurry(int o, int l, int r)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (x[lch[o]] >= x[rch[o]])
        return qurry(lch[o], l, mid);
    else
        return qurry(rch[o], mid + 1, r);
}
int getf(int o, int l, int r, int p)
{
    if (l == r)
        return x[o];
    int mid = (l + r) >> 1;
    if (p <= mid)
        return getf(lch[o], l, mid, p);
    else
        return getf(rch[o], mid + 1, r, p);
}
int n, m;
int fa[maxn][20];
int dep[maxn];
int ans[maxn];
void dfs1(int x, int f)
{
    fa[x][0] = f;
    dep[x] = dep[f] + 1;
    for (int i = 1; i < 20; i++)
    {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (int i = 0; i < G[x].size(); i++)
    {
        if (G[x][i] != f)
            dfs1(G[x][i], x);
    }
}

int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    int delta = dep[x] - dep[y];
    for (int i = 0; i < 20; i++)
    {
        if (delta & (1 << i))
        {
            x = fa[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 19; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
void dfs2(int x, int f)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        int v = G[x][i];
        if (v == f)
            continue;
        dfs2(v, x);
        rt[x] = merge(rt[v], rt[x], 0, maxn);
    }
    ans[x] = qurry(rt[x], 0, maxn);
}
int main()
{
    read(n, m);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        read(x, y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
    {
        rt[i] = ++tot;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        read(x, y, z);
        modify(rt[x], 0, maxn, z, 1);
        modify(rt[y], 0, maxn, z, 1);
        int l = lca(x, y);
        modify(rt[l], 0, maxn, z, -1);
        if(fa[l][0])
            modify(rt[fa[l][0]], 0, maxn, z ,-1);
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}