#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#define PAS system("pause")
#define CHK  //printf("run to %s at line %d\n",__FUNCTION__,__LINE__)
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
using namespace std;
#define LL long long
const int maxn = 200010;
struct Node
{
    LL fa, deep;
    Node *lch, *rch;
    Node()
    {
        fa = deep = 0;
        lch = rch = 0;
    }
};
Node *root[maxn];
void build(Node *&curr, int l, int r)
{
    curr = new Node();
    if (l == r)
    {
        curr->fa = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(curr->lch, l, mid);
    build(curr->rch, mid + 1, r);
}
void update(Node *&curr, Node *pre, int l, int r, int pos, int ff)
{
    CHK;
    curr = new Node();
    if (l == r)
    {
        curr->fa = ff;
        curr->deep = pre->deep;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        curr->rch = pre->rch;
        update(curr->lch, pre->lch, l, mid, pos, ff);
    }
    else
    {
        curr->lch = pre->lch;
        update(curr->rch, pre->rch, mid + 1, r, pos, ff);
    }
}
Node *qurry(Node *curr, int l, int r, int pos)
{
    CHK;
    if (l == r)
        return curr;
    int mid = (l + r) >> 1;
    if (pos<=mid)
        return qurry(curr->lch, l, mid, pos);
    else
        return qurry(curr->rch, mid + 1, r, pos);
}
int n, m;
void add(Node *curr, int l, int r, int pos)
{
    CHK;
    if (l == r)
    {
        curr->deep++;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        add(curr->lch, l, mid, pos);
    else
        add(curr->rch, mid + 1, r, pos);
}
Node *find_fa(Node *ed, int x)
{
    CHK;
    Node *ff = qurry(ed, 1, n, x);
    if (x == ff->fa)
        return ff;
    else
        return find_fa(ed, ff->fa);
}
int main()
{
    read(n, m);
    CHK;
    build(root[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt;
        read(opt);
        if (opt == 1)
        {
            root[i] = root[i - 1];
            int a, b;
            read(a, b);
            Node *f1 = find_fa(root[i], a);
            Node *f2 = find_fa(root[i], b);
            if (f1->fa == f2->fa)
                continue;
            if (f1->deep > f2->deep)
                swap(f1, f2);
            update(root[i], root[i - 1], 1, n, f1->fa, f2->fa);
            if (f1->deep == f2->deep)
                add(root[i], 1, n, f2->fa);
        }
        if (opt == 2)
        {
            int k;
            read(k);
            root[i] = root[k];
        }
        if (opt == 3)
        {
            root[i] = root[i - 1];
            int a, b;
            read(a, b);
            Node *f1 = find_fa(root[i], a);
            Node *f2 = find_fa(root[i], b);
            if (f1->fa == f2->fa)
                puts("1");
            else
                puts("0");
        }
    }
}