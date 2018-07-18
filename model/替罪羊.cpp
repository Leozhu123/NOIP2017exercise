#include <iostream>
#include <vector>
const double alpha = 0.7;
using namespace std;
struct Node
{
    Node *lch, *rch;
    int x, sz, cnt;
    bool deleted;
    Node()
    {
        lch = rch = 0;
        x = sz = cnt = 0;
        deleted = 0;
    }
    bool isbad()
    {
        return lch->sz > sz * alpha + 5 || rch->sz > sz * alpha + 5 || sz < cnt * alpha;
    }
    void maintain()
    {
        sz = 1 + lch->sz + rch->sz;
        cnt = !deleted + lch->cnt + rch->cnt;
    }
};
Node *null = new Node;
Node *root = null;
void dfs(Node *o, vector<Node *> &v)
{
    if (o == null)
        return;
    dfs(o->lch, v);
    if (!o->deleted)
        v.push_back(o);
    dfs(o->rch, v);
    if (o->deleted)
        delete o;
}
Node *build(vector<Node *> &v, int l, int r)
{
    if (l >= r)
        return null;
    int mid = (l + r) >> 1;
    Node *o = v[mid];
    o->lch = build(v, l, mid);
    o->rch = build(v, mid + 1, r);
    o->maintain();
    return o;
}
void rebuild(Node *&o)
{
    vector<Node *> v;
    dfs(o, v);
    o = build(v, 0, v.size());
}
void insert(int x, Node *&o)
{
    if (o == null)
    {
        o = new Node;
        o->lch = o->rch = null;
        o->sz = o->cnt = 1;
        o->x = x;
        return;
    }
    o->sz++;
    o->cnt++;
    if (x <= o->x)
    {
        insert(x, o->lch);
    }
    else
    {
        insert(x, o->rch);
    }
    if (o->isbad())
        rebuild(o);
}