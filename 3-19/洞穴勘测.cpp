#include <iostream>
using namespace std;
const long long maxn = 300005;
long long da[maxn];
struct SplayNode
{
    SplayNode *lch, *rch, *father, *path_parent;
    long long idx, xo;
    bool isRev;
    SplayNode(long long idx)
    {
        lch = rch = father = path_parent = 0;
        isRev = false;
        xo = 0;
        this->idx = idx;
    }
    void update()
    {
        xo = 0;
        if (lch)
            xo ^= lch->xo;
        if (rch)
            xo ^= rch->xo;
        xo = xo ^ da[idx];
    }
    void pushdown()
    {
        if (isRev)
        {
            if (rch)
                rch->isRev = !rch->isRev;
            if (lch)
                lch->isRev = !lch->isRev;
            isRev = false;
            SplayNode *t = lch;
            lch = rch;
            rch = t;
        }
        update();
    }
    void leftroute()
    {
        SplayNode *y = father;
        path_parent = y->path_parent;
        y->path_parent = 0;
        y->rch = lch;
        if (lch)
        {
            lch->father = y;
        }
        father = y->father;
        if (y->father)
        {
            if (y == y->father->lch)
                y->father->lch = this;
            else
                y->father->rch = this;
        }
        y->father = this;
        lch = y;
        y->update();
        update();
    }
    void rightroute()
    {
        SplayNode *y = father;
        path_parent = y->path_parent;
        y->path_parent = 0;
        y->lch = rch;
        if (rch)
        {
            rch->father = y;
        }
        father = y->father;
        if (y->father)
        {
            if (y == y->father->lch)
                y->father->lch = this;
            else
                y->father->rch = this;
        }
        y->father = this;
        rch = y;
        y->update();
        update();
    }
    void rev()
    {
        isRev = !isRev;
        pushdown();
    }
};
SplayNode *location[maxn];
void splay(SplayNode *x)
{
    while (x->father)
    {
        SplayNode *father = x->father;
        x->father->pushdown();
        if (father->lch)
            father->lch->pushdown();
        if (father->rch)
            father->rch->pushdown();
        if (x == x->father->lch)
        {
            x->rightroute();
        }
        else
        {
            x->leftroute();
        }
    }
}
void Access(SplayNode *p)
{
    splay(p);
    p->pushdown();
    SplayNode *q = p->rch;
    if (q)
    {
        p->rch = q->father = 0;
        p->update();
        q->path_parent = p;
    }
    p->pushdown();
    for (q = p->path_parent; q; q = p->path_parent)
    {
        splay(q);
        splay(p);
        q->pushdown();
        SplayNode *r = q->rch;
        q->rch = p;
        q->update();
        q->father = 0;
        if (r)
        {
            r->path_parent = q;
            r->father = 0;
        }
        p->father = q;
        p->path_parent = 0;
        p = q;
    }
    splay(p);
}
SplayNode *FindRoot(SplayNode *p)
{
    Access(p);
    splay(p);
    p->pushdown();
    while (p && p->lch)
    {
        p = p->lch;
        p->pushdown();
    }
    splay(p);
    p->pushdown();
    return p;
}
void Evert(SplayNode *p)
{
    Access(p);
    splay(p);
    p->rev();
    p->pushdown();
}
void Cut(SplayNode *p, SplayNode *q)
{
    Evert(p);
    Access(q);
    splay(q);
    q->pushdown();
    if (q->lch)
        q->lch->father = 0;
    q->lch = 0;
    q->update();
}
void Link(SplayNode *p, SplayNode *q)
{
    Evert(p);
    splay(p);
    p->pushdown();
    Access(q);
    splay(q);
    q->pushdown();
    p->lch = q;
    p->update();
    q->father = p;
    q->path_parent = 0;
    p->pushdown();
}
void MakeTree(long long idx)
{
    SplayNode *p = new SplayNode(idx);
    location[idx] = p;
    p->xo = da[idx];
}
long long ask(SplayNode *p, SplayNode *q)
{
    Evert(p);
    splay(p);
    p->pushdown();
    Access(q);
    splay(q);
    q->pushdown();
    return q->xo;
}
void change(long long idx, long long x)
{
    da[idx] = x;
    SplayNode *cur = location[idx];
    splay(cur);
    cur->update();
}
int main()
{
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        MakeTree(i);
    }
    for (long long i = 0; i < m; i++)
    {
        long long a, b;
        char str[100];
        scanf("%s %lld%lld", str, &a, &b);
        if (str[0] == 'Q')
        {
            if (FindRoot(location[a]) == FindRoot(location[b]))
            {
                cout << "Yes" << endl;
            }else {
                cout << "No" << endl;
            }
        }
        else if (str[0] == 'C')
        {
            if (FindRoot(location[a]) != FindRoot(location[b]))
            {
                Link(location[a], location[b]);
            }
        }
        else if (str[0] == 'D')
        {
            if (FindRoot(location[a]) == FindRoot(location[b]))
            {
                Cut(location[a], location[b]);
            }
        }
    }
}
