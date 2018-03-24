#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const long long maxn = 210000;
struct Node
{
    long long sum, l, r;
    Node *lch, *rch;
    Node(long long s, long long l, long long r) : sum(s), l(l), r(r)
    {
        lch = rch = 0;
    }
};
Node *root[maxn];
void build(Node *&curr, long long l, long long r)
{
    curr = new Node(0, l, r);
    long long mid = (l + r) >> 1;
    if (l == r)
        return;
    build(curr->lch, l, mid);
    build(curr->rch, mid + 1, r);
}
void update(Node *curr, Node *pre, long long x)
{
    curr->sum = pre->sum + 1;
    if (curr->l == curr->r)
        return;
    long long mid = (curr->l + curr->r) >> 1;
    if (x <= mid)
    {
        delete curr->lch;
        curr->lch = new Node(0, curr->l, mid);
        curr->rch = pre->rch;
        update(curr->lch, pre->lch, x);
    }
    else
    {
        delete curr->rch;
        curr->rch = new Node(0, mid + 1, curr->r);
        curr->lch = pre->lch;
        update(curr->rch, pre->rch, x);
    }
}
long long query(Node *st, Node *ed, long long x)
{
    if (st->l == st->r)
        return st->l;

    long long s = ed->lch->sum - st->lch->sum;
    if (x <= s)
    {
        return query(st->lch, ed->lch, x);
    }
    else
    {
        return query(st->rch, ed->rch, x - s);
    }
}
long long n, q;
long long num[maxn], num2[maxn];
int main()
{
    cin>>n>>q;
    for (long long i = 1; i <= n; i++)
    {
        cin >> num[i];
        num2[i] = num[i];
    }
    sort(num2 + 1, num2 + 1 + n);
    long long size = unique(num2 + 1, num2 + n + 1) - (num2 + 1);
    build(root[0], 1, size);
    for (long long i = 1; i <= n; i++)
    {
        long long t = lower_bound(num2 + 1, num2 + 1 + size, num[i]) - num2;
        root[i] = new Node(0, root[i - 1]->l, root[i - 1]->r);
        update(root[i], root[i - 1], t);
    }
    for (long long i = 1; i <= q; i++)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        cout<<num2[query(root[x-1], root[y], z)]<<endl;
    }
}