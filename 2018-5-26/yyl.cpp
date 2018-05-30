#include <bits/stdc++.h>
#define N 301000
#define ll long long
using namespace std;
int n, m, q, w, tot;
struct node
{
    int l, r, d;
} t[N * 100];
vector<ll> a[N];
int find(int v, int i, int j, int x)
{
    if (i == j)
        return i;
    int m = (i + j) / 2;
    if (x <= m - i + 1 - t[t[v].l].d)
        return find(t[v].l, i, m, x);
    return find(t[v].r, m + 1, j, x - (m - i + 1 - t[t[v].l].d));
}
void change(int v, int i, int j, int x)
{
    t[v].d++;
    if (i == j)
        return;
    int m = (i + j) / 2;
    if (x <= m)
    {
        if (t[v].l == 0)
        {
            tot++;
            t[v].l = tot;
        }
        change(t[v].l, i, m, x);
    }
    else
    {
        if (t[v].r == 0)
        {
            tot++;
            t[v].r = tot;
        }
        change(t[v].r, m + 1, j, x);
    }
}
int main()
{
    //freopen("phalanx.in","r",stdin);
    //freopen("phalanx.out","w",stdout);
    scanf("%d%d%d", &n, &m, &q);
    w = max(n, m) + q + 1;
    tot = n + 1;
    for (; q; q--)
    {
        int x, y;
        ll ans = 0;
        scanf("%d%d", &x, &y);
        if (y != m)
        {
            int z = find(x, 1, w, y);
            if (z < m)
                ans = (x - 1) * (ll)m + z;
            else
                ans = a[x][z - m];
            change(x, 1, w, z);
            a[n + 1].push_back(ans);
            z = find(n + 1, 1, w, x);
            if (z > n)
                a[x].push_back(a[n + 1][z - n - 1]);
            else
                a[x].push_back((ll)z * (ll)m);
            change(n + 1, 1, w, z);
        }
        else
        {
            int z = find(n + 1, 1, w, x);
            if (z > n)
                ans = a[n + 1][z - n - 1];
            else
                ans = (ll)z * (ll)m;
            change(n + 1, 1, w, z);
            a[n + 1].push_back(ans);
        }
        printf("%lld\n", ans);
    }
}
