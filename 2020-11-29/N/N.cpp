#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
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
typedef int arrT[200010];
arrT v, head, next, value;
arrT top, fa, son, dfn, newval, dep, size;
int n, m, r, p, total, index;

struct Node
{
    int lb = 0, rb = 0;
    int sum = 0, delta = 0;
    int lc = 0, rc = 0;
    Node() = default;
    Node(int l, int r, int s) : lb(l), rb(r), sum(s) {}
    int size() const { return rb - lb + 1; }
    bool unique() const { return size() == 1; }
    bool covered(int l, int r) const
    {
        return l <= lb && r >= rb;
    }
    bool out(int l, int r) const
    {
        return l > rb || r < lb;
    }
};

Node segtree[500010];
int segend = 1;
Node &root = segtree[1];

inline Node &left(const Node &curr)
{
    return segtree[curr.lc];
}
inline Node &right(const Node &curr)
{
    return segtree[curr.rc];
}

inline void buildSegTree(Node &curr, int l, int r)
{
    curr = Node(l, r, 0);
    if (curr.unique())
    {
        curr.sum = newval[l];
        return;
    }
    curr.lc = ++segend;
    curr.rc = ++segend;
    int mid = (l + r) >> 1;
    buildSegTree(left(curr), l, mid);
    buildSegTree(right(curr), mid + 1, r);
    curr.sum = left(curr).sum + right(curr).sum;
}

inline void pushdown(Node &curr)
{
    left(curr).sum = (left(curr).sum + left(curr).size() * curr.delta);
    right(curr).sum = (right(curr).sum + right(curr).size() * curr.delta);
    left(curr).delta = (left(curr).delta + curr.delta);
    right(curr).delta = (right(curr).delta + curr.delta);
    curr.delta = 0;
}

inline int segQuery(Node &curr, int l, int r)
{
    if (curr.out(l, r))
        return 0;
    if (curr.covered(l, r))
        return curr.sum;
    if (curr.delta)
        pushdown(curr);
    return (segQuery(left(curr), l, r) + segQuery(right(curr), l, r));
}

inline void segModify(Node &curr, int l, int r, int d)
{
    if (curr.out(l, r))
        return;
    if (curr.covered(l, r))
    {
        curr.sum = (curr.sum + curr.size() * d);
        curr.delta = (curr.delta + d);
        return;
    }
    if (curr.delta)
        pushdown(curr);
    segModify(left(curr), l, r, d);
    segModify(right(curr), l, r, d);
    curr.sum = (left(curr).sum + right(curr).sum);
}

inline void add_edge(int x, int y)
{
    v[++total] = y;
    next[total] = head[x];
    head[x] = total;
}

// dfs1 will work out dep[], son[], size[], fa[]
inline void dfs1(int x)
{
    size[x] = 1;
    dep[x] = dep[fa[x]] + 1;
    for (int i = head[x]; i; i = next[i])
    {
        if (v[i] != fa[x])
        {
            fa[v[i]] = x;
            dfs1(v[i]);
            size[x] += size[v[i]];
            if (size[v[i]] > size[son[x]])
                son[x] = v[i];
        }
    }
}

// dfs2 will work out top[], dfn[], newval[]
inline void dfs2(int x, int t)
{
    dfn[x] = ++index;
    top[x] = t;
    newval[dfn[x]] = value[x];
    if (son[x])
        dfs2(son[x], t);
    for (int i = head[x]; i; i = next[i])
        if (v[i] != son[x] && v[i] != fa[x])
            dfs2(v[i], v[i]);
}

inline void pathInc(int x, int y, int d)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        segModify(root, dfn[top[x]], dfn[x], d);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        std::swap(x, y);
    segModify(root, dfn[y], dfn[x], d);
}

inline int pathQuery(int x, int y)
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        ans = (ans + segQuery(root, dfn[top[x]], dfn[x]));
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        std::swap(x, y);
    ans = (ans + segQuery(root, dfn[y], dfn[x]));
    return ans;
}

inline void treeInc(int x, int d)
{
    segModify(root, dfn[x], dfn[x], d);
}

inline int treeQuery(int x)
{
    return segQuery(root, dfn[x], dfn[x] + size[x] - 1);
}

int main()
{
    read(n);
    r = 1;
    for (int i = 1; i <= n; ++i)
        read(value[i]);
    for (int i = 2; i <= n; ++i)
    {
        int p;
        read(p);
        add_edge(i, p);
        add_edge(p, i);
    }
    dfs1(r);
    dfs2(r, r);
    buildSegTree(root, 1, n);
    read(m);
    while (m--)
    {
        int q;
        read(q);
        switch (q)
        {
        case 1:
        {
            int x, z;
            read(x, z);
            treeInc(x, z - value[x]);
            value[x] = z;
            break;
        }
        case 2:
        {
            int x;
            read(x);
            cout << treeQuery(x) << endl;
            break;
        }
        }
    }
    return 0;
}