#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const long long maxn = 3e5 + 500, maxm = 1e7;
struct Node
{
    long long sum;
    long long val;
    Node *lch, *rch;
    Node()
    {
        lch = rch = 0;
        val = 0;
    }
    Node(long long s)
    {
        sum = s;
        lch = rch = 0;
        val = 0;
    }
};
long long n, m, q;
long long get_sz(long long l, long long r, long long now)
{
    if (now == n + 1)
    {
        if (r <= n)
            return r - l + 1;
        if (l <= n)
            return n - l + 1;
        return 0;
    }
    else
    {
        if (r < m)
            return r - l + 1;
        if (l < m)
            return m - l;
        return 0;
    }
}
long long query(Node *&curr, long long l, long long r, long long x, long long now)
{
    if (!curr)
    {
        curr = new Node(get_sz(l, r, now));
        if (l == r)
        {
            if (now <= n)
                curr->val = (now - 1) * m + l;
            else
                curr->val = l * m;
        }
    }
    curr->sum--;
    if (l == r)
        return curr->val;
    long long mid = (l + r) >> 1;
    if ((curr->lch == 0 && x <= (mid - l + 1)) || curr->lch != 0 && x <= curr->lch->sum)
        return query(curr->lch, l, mid, x, now);
    else
    {
        if (!curr->lch)
            x -= (mid - l + 1);
        else
            x -= curr->lch->sum;
        return query(curr->rch, mid + 1, r, x, now);
    }
}
void update(Node *&curr, long long l, long long r, long long x, long long w, long long now)
{
    if (!curr)
    {
        curr = new Node(get_sz(l, r, now));
        if (l == r)
        {
            curr->val = w;
        }
    }
    curr->sum++;
    if (l == r)
        return;
    long long mid = (l + r) >> 1;
    if (x <= mid)
        update(curr->lch, l, mid, x, w, now);
    else
        update(curr->rch, mid + 1, r, x, w, now);
}
Node *root[maxn];
long long o[maxn];
int main()
{
    long long x, y, q;
    cin >> n >> m >> q;
    long long p = max(n, m) + q;
    for (long long i = 0; i < q; i++)
    {
        cin >> x >> y;
        long long z;
        long long now;
        if (y == m)
            now = n + 1, z = query(root[now], 1, p, x, now);
        else
            now = x, z = query(root[now], 1, p, y, now);
        printf("%lld\n", z);
        now = n + 1;
        update(root[n + 1], 1, p, n + (++o[n + 1]), z, now);
        if (y != m)
        {
            now = n + 1;
            z = query(root[now], 1, p, x, now);
            now = x;
            update(root[x], 1, p, m - 1 + (++o[x]), z, now);
        }
    }
}
