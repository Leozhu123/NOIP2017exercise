#include <algorithm>
#include <cstdio>
#include <iostream>
const int INF = (1 << 31) - 1;
const int maxn = 1000007;
using namespace std;
struct Node
{
    Node *ch[2], *fa;
    int sz, x;
    bool mark;
    Node()
    {
        ch[0] = ch[1] = fa = 0;
        sz = x = 0;
        mark = false;
    }
    void maintain()
    {
        if (mark)
        {
            Node *t = ch[0];
            ch[0] = ch[1];
            ch[1] = t;
            ch[0]->mark = !ch[0]->mark;
            ch[1]->mark = !ch[1]->mark;
            mark = false;
        }
        sz=1;
        if(ch[0]) sz+=ch[0]->sz;
        if(ch[1]) sz+=ch[1]->sz;
    }
};
Node *null=new Node;
Node *root = null;
int date[maxn];
inline bool which(Node *x)
{
    return x == x->fa->ch[1];
}
void rotate(Node *curr)
{
    Node *fnow = curr->fa;
    Node *ffnow = fnow->fa;
    curr->maintain();
    fnow->maintain();
    int w = curr == fnow->ch[0] ? 0 : 1;
    fnow->ch[w] = curr->ch[w ^ 1];
    fnow->ch[w]->fa = fnow;
    fnow->fa = curr;
    curr->fa = ffnow;
    curr->ch[w ^ 1] = fnow;
    if (ffnow)
    {
        ffnow->ch[ffnow->ch[1] == fnow] = curr;
    }
    fnow->maintain();
}
void splay(Node *x, Node *goal)
{
    for (Node *qwq; (qwq = x->fa) != goal; rotate(x))
    {
        if (qwq->fa != goal)
        {
            rotate(which(x) == which(qwq) ? qwq : x);
        }
    }
    if (goal == null)
    {
        root = x;
    }
}
Node *build_tree(Node *fa, int l, int r)
{
    if (l > r)
        return null;
    int mid = (l + r) >> 1;
    Node *now = new Node;
    now->ch[0]=now->ch[1]=null;
    now->fa = fa;
    now->x = date[mid];
    now->maintain();
    now->ch[0] = build_tree(now, l, mid-1);
    now->ch[1] = build_tree(now, mid + 1, r);
    now->maintain();
    return now;
}
Node *find(int x)
{
    Node *now = root;
    while (1)
    {
        now->maintain();
        if (x <= now->ch[0]->sz)
        {
            now = now->ch[0];
        }
        else 
		{
            x -= now->ch[0]->sz + 1;
            if (!x)
                return now;
            now = now->ch[1];
        }
    }
}
void reverse(int x, int y)
{
    int l = x - 1, r = y + 1;
    Node *ll = find(l), *rr = find(r);
    splay(ll, null);
    splay(rr, ll);
    root->ch[1]->ch[0]->mark = !root->ch[1]->ch[0]->mark;
}
void dfs(Node *now)
{
    now->maintain();
    if (now->ch[0]!=null)
        dfs(now->ch[0]);
    if (now->x != -INF && now->x != INF)
    {
        cout << now->x << " ";
    }
    if (now->ch[1]!=null)
        dfs(now->ch[1]);
}
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    date[1] = -INF, date[n + 2] = INF;
    for (int i = 1; i <= n; i++)
    {
        date[i + 1] = i;
    }
    root = build_tree(null,1, n + 2);
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        reverse(x + 1, y + 1);
    }
    dfs(root);
}
