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

int n, m;
int main()
{
    cin >> n >> m;
}