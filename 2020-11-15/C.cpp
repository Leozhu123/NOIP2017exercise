#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
#define N 910007
using namespace std;
int n, m, ans = INT_MAX, ti;
void read(int &x)
{
    static char c;
    static int b;
    for (b = 1, c = getchar(); !isdigit(c); c = getchar())
        if (c ==‘-‘)
            b = -1;
    for (x = 0; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    x *= b;
}
struct edge
{
    int x, y, z;
    inline bool operator<(const edge &A) const
    {
        return z < A.z;
    }
} e[N];
namespace snow
{
    int ch[N][2], fa[N], r[N], mi[N], val[N], id, usd[N];
    bool isroot(int x)
    {
        return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
    }
    void rev(int x)
    {
        r[x] ^= 1;
        swap(ch[x][0], ch[x][1]);
    }
    void pushdown(int x)
    {
        if (!isroot(x))
            pushdown(fa[x]);
        if (r[x])
        {
            if (ch[x][0])
                rev(ch[x][0]);
            if (ch[x][1])
                rev(ch[x][1]);
            r[x] = 0;
        }
    }
    void pushup(int x)
    {
        mi[x] = val[mi[ch[x][0]]] < val[mi[ch[x][1]]] ? mi[ch[x][0]] : mi[ch[x][1]];
        mi[x] = val[mi[x]] < val[x] ? mi[x] : x;
    }
    void rotate(int x)
    {
        int y = fa[x], z = fa[y], l, r;
        if (ch[y][0] == x)
            l = 0;
        else
            l = 1;
        r = l ^ 1;
        if (!isroot(y))
            ch[z][ch[z][1] == y] = x;
        fa[x] = z;
        fa[ch[x][r]] = y;
        fa[y] = x;
        ch[y][l] = ch[x][r];
        ch[x][r] = y;
        pushup(x);
        pushup(y);
    }
    void splay(int x)
    {
        pushdown(x);
        while (!isroot(x))
        {
            int y = fa[x], z = fa[y];
            if (!isroot(y))
            {
                if (ch[y][0] == x ^ ch[z][0] == y)
                    rotate(x);
                else
                    rotate(y);
            }
            rotate(x);
        }
    }
    void access(int x)
    {
        int y = 0;
        while (x)
        {
            splay(x);
            ch[x][1] = y;
            pushup(x);
            y = x;
            x = fa[x];
        }
    }
    void beroot(int x)
    {
        access(x);
        splay(x);
        rev(x);
    }
    int root(int x)
    {
        access(x);
        splay(x);
        while (ch[x][0])
            x = ch[x][0];
        return x;
    }
    void link(int x, int y)
    {
        beroot(x);
        fa[x] = y;
    }
    void cut(int x, int y)
    {
        beroot(x);
        access(y);
        splay(y);
        if (ch[y][0] == x)
            ch[y][0] = 0;
        fa[x] = 0;
    }
    void sol()
    {
        for (int i = 1; i <= m; i++)
            read(e[i].x), read(e[i].y), read(e[i].z);
        sort(e + 1, e + m + 1);
        ans = INT_MAX;
        for (int i = 0; i <= n; i++)
            val[i] = INT_MAX;
        for (int i = 1; i <= m; i++)
            val[n + i] = e[i].z;
        int to = 1;
        for (int i = 1; i <= m; i++)
        {
            beroot(e[i].x);
            if (root(e[i].y) != e[i].x)
            {
                link(n + i, e[i].x);
                link(n + i, e[i].y);
                ti++;
            }
            else
            {
                id = mi[e[i].y];
                usd[id - n] = 1;
                cut(id, e[id - n].x);
                cut(id, e[id - n].y);
                link(n + i, e[i].x);
                link(n + i, e[i].y);
            }
            while (usd[to])
                to++;
            if (ti == n - 1)
                ans = min(ans, e[i].z - e[to].z);
        }
        printf("%d\n", ans == INT_MAX ? -1 : ans);
    }
} // namespace snow
signed main()
{
    read(n);
    read(m);
    snow::sol();
}