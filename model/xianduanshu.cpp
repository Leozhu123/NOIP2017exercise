#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct Node
{
    int lb, rb;
    int sum, delta;
    int lc, rc;
    Node(int l = 0, int r = 0, int s = 0) : lb(l), rb(r), sum(s), delta(0), lc(0), rc(0) {}
    int size() { return rb - lb + 1; }
    bool unique() { return lb == rb; }
    bool out(int l, int r)
    {
        return l > rb || r < lb;
    }
    bool covered(int l, int r)
    {
        return l <= lb && rb <= r;
    }
    Node &left();
    Node &right();
};
Node segtree[400010];
int a[100010], segend = 1;
Node &Node::left()
{
    return segtree[lc];
}
Node &Node::right()
{
    return segtree[rc];
}
Node &root = segtree[1];
inline void pushdown(Node &curr)
{
    if (curr.delta)
    {
        curr.left().sum += curr.left().size() * curr.delta;
        curr.right().sum += curr.right().size() * curr.delta;
        curr.left().delta += curr.delta;
        curr.right().delta += curr.delta;
        curr.delta = 0;
    }
}
inline void getup(Node &curr)
{
    curr.sum = curr.left().sum + curr.right().sum;
}
inline void build(Node &curr, int l, int r)
{
    curr = Node(l, r, 0);
    if (curr.unique())
    {
        curr.sum = a[l];
        return;
    }
    curr.lc = ++segend;
    curr.rc = ++segend;
    int mid = (l + r) >> 1;
    build(curr.left(), l, mid);
    build(curr.right(), mid + 1, r);
    getup(curr);
}
inline void modify(Node &curr, int l, int r, int d)
{
    if (curr.out(l, r))
        return;
    if (curr.covered(l, r))
    {
        curr.sum += curr.size() * d;
        curr.delta += d;
        return;
    }
    pushdown(curr);
    modify(curr.left(), l, r, d);
    modify(curr.right(), l, r, d);
    getup(curr);
}
inline int querysum(Node &curr, int l, int r)
{
    if (curr.out(l, r))
        return 0;
    if (curr.covered(l, r))
        return curr.sum;
    pushdown(curr);
    return querysum(curr.left(), l, r) + querysum(curr.right(), l, r);
}
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(root, 1, n);
    while (m--)
    {
        int q;
        cin >> q;
        int x, y;
        cin >> x >> y;
        if (q == 1)
        {
            int d;
            cin >> d;
            modify(root, x, y, d);
        }
        else
        {
            cout << querysum(root, x, y) << endl;
        }
    }
    return 0;
}