#include <iostream>
using namespace std;
struct Node
{
    int lb, rb, lc, rc, sum, delta;
    explicit Node(int l = 0, int r = 0, int s = 0)
        : lb(l), rb(r), lc(0), rc(0), delta(0) {}
    int size() { return rb - lb + 1; }
    bool unique() { return rb == lb; }
    bool out(int l, int r)
    {
        return l > rb || r < lb;
    }
    bool covered(int l, int r)
    {
        return l >= lb && r <= rb;
    }
    Node &left();
    Node &right();
};
Node segtree[400000];
int segend = 1;
Node &root = segtree[1];
int a[100000];
int n, m;
Node &Node::left()
{
    return segtree[lc];
}
Node &Node::right()
{
    return segtree[rc];
}
void pushdown(Node &curr)
{
    curr.left().sum += curr.left().size() * curr.delta;
    curr.right().sum += curr.right().size() * curr.delta;
    curr.left().delta += curr.delta;
    curr.right().sum += curr.delta;
    curr.delta = 0;
}
void getup(Node &curr)
{
    curr.sum = curr.left().sum + curr.right().sum;
}
void build(Node &curr, int l, int r)
{
    curr = Node(l, r);
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
void modify(Node &curr, int l, int r, int d)
{
    if (curr.out(l, r))
        return;
    if (curr.covered(l, r))
    {
        curr.sum += d * curr.size();
        curr.delta += d;
    }
    pushdown(curr);
    modify(curr.left(), l, r, d);
    modify(curr.right(), l, r, d);
    getup(curr);
}
int querySum(Node &curr, int l, int r)
{
    if (curr.out(l, r))
        return 0;
    if (curr.covered(l, r))
    {
        return curr.sum;
    }
    pushdown(curr);
    return querySum(curr.left(), l, r) + querySum(curr.right(), l, r);
}