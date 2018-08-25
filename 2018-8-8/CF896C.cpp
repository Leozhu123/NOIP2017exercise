#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define IT set<node>::iterator

using namespace std;

const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int imax_n = 1e5 + 7;
typedef long long LL;
LL pow(LL a, LL b, LL mod)
{
    LL res = 1;
    LL ans = a % mod;
    while (b)
    {
        if (b & 1)
            res = res * ans % mod;
        ans = ans * ans % mod;
        b >>= 1;
    }
    return res;
}
struct node
{
    int l, r;
    mutable LL val;
    node(int a, int b = -1, int c = 0)
    {
        l = a;
        r = b;
        val = c;
    }
    bool operator<(const node &o) const
    {
        return l < o.l;
    }
};

set<node> s;

IT split(int pos)
{
    IT it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos)
        return it;
    it--;
    int l = it->l, r = it->r;
    int v = it->val;
    s.erase(it);
    s.insert(node(l, pos - 1, v));
    return s.insert(node(pos, r, v)).first;
}

void assign_val(int l, int r, LL v=0)
{
    IT itl = split(l), itr = split(r + 1);
    s.erase(itl, itr);
    s.insert(node(l, r, v));
}

void add(int l, int r, LL x)
{
    IT itl = split(l), itr = split(r + 1);
    for (; itl != itr; itl++)
    {
        itl->val += x;
    }
}

int rankk(int l, int r, int k)
{
    IT itl = split(l), itr = split(r+1);
    vector<pair<LL, int> > vp;
    for (; itl != itr; itl++)
    {
        vp.push_back(pair<LL, int>(itl->val, itl->r - itl->l + 1));
    }
    sort(vp.begin(), vp.end());
    for (vector<pair<LL, int> >::iterator it = vp.begin(); it != vp.end(); ++it)
    {
        k -= it->second;
        if (k <= 0)
            return it->first;
    }
    return (int)-1;
}

int sum(int l, int r, int k, int mod)
{
    IT itl = split(l), itr = split(r+1);
    int res = 0;
    for (; itl != itr; ++itl)
        res = (res + (LL)(itl->r - itl->l + 1) * pow(itl->val, int(k), int(mod))) % mod;
    return res;
}

int n, m;

LL seed, vmax;

LL rnd()
{
    LL ret = seed;
    seed = (seed * 7 + 13) % MOD7;
    return ret;
}

LL a[imax_n];

int main()
{
    cin >> n >> m >> seed >> vmax;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = (rnd() % vmax) + 1;
        s.insert(node(i, i, a[i]));
    }
    s.insert(node(n + 1, n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        int op = int(rnd() % 4) + 1;
        int l = int(rnd() % n) + 1;
        int r = int(rnd() % n) + 1;
        if (l > r)
            swap(l, r);
        int x, y;
        if (op == 3)
            x = int(rnd() % (r - l + 1)) + 1;
        else
            x = int(rnd() % vmax) + 1;
        if (op == 4)
            y = int(rnd() % vmax) + 1;
        if (op == 1)
            add(l, r, x);
        else if (op == 2)
            assign_val(l, r, x);
        else if (op == 3)
            cout<<rankk(l, r, x);
        else
            cout<<sum(l, r, x, y);
    }
    return 0;
}