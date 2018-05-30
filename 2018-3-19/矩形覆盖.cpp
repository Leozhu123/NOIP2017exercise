#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
const int maxn = 10000000;
using namespace std;
struct Node
{
    Node *lch, *rch;
    int st, ed;
    double m;
    int c;
    Node(int l, int r) : st(l), ed(r)
    {
        lch = rch = 0;
        m = 0;
        c = 0;
    }
};
struct line
{
    double x, y1, y2;
    bool s;
};
line Line[maxn];
int num;
double y[maxn], ty[maxn];
Node *root;
void build(Node *&curr, int st, int ed)
{
    curr = new Node(st, ed);
    if (ed - st > 1)
    {
        int mid = (st + ed) >> 1;
        build(curr->lch, st, mid);
        build(curr->rch, mid, ed);
    }
}
void update(Node *curr)
{
    if (curr->c > 0)
    {
        curr->m = y[curr->ed - 1] - y[curr->st - 1];
    }
    else if (curr->ed - curr->st == 1)
    {
        curr->m = 0;
    }
    else
    {
        curr->m = curr->lch->m + curr->rch->m;
    }
}
void insert(Node *curr, int st, int ed)
{
    if (st <= curr->st && curr->ed <= ed)
    {
        curr->c++;
        update(curr);
        return;
    }
    int mid = (curr->st + curr->ed) >> 1;
    if (st < mid)
        insert(curr->lch, st, ed);
    if (ed > mid)
        insert(curr->rch, st, ed);
    update(curr);
}
void del(Node *curr, int st, int ed)
{
    if (st <= curr->st && curr->ed <= ed)
    {
        curr->c--;
        update(curr);
        return;
    }
    int mid = (curr->st + curr->ed) >> 1;
    if (st < mid)
        del(curr->lch, st, ed);
    if (ed > mid)
        del(curr->rch, st, ed);
    update(curr);
}
map<double, int> indexs;
bool cmp(line l1, line l2)
{
    return l1.x < l2.x;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Line[i << 1].x = x1;
        Line[i << 1].y1 = y1;
        Line[i << 1].y2 = y2;
        Line[i << 1].s = 1;
        Line[(i << 1) + 1].x = x2;
        Line[(i << 1) + 1].y1 = y1;
        Line[(i << 1) + 1].y2 = y2;
        Line[(i << 1) + 1].s = 0;
        ty[i << 1] = y1;
        ty[(i << 1) + 1] = y2;
    }
    n <<= 1;
    sort(Line, Line + n, cmp);
    sort(ty, ty + n);
    y[0] = ty[0];
    for (int i = num = 1; i < n; i++)
    {
        if (ty[i] != ty[i - 1])
        {
            y[num++] = ty[i];
        }
    }
    for (int i = 0; i < num; i++)
    {
        indexs[y[i]] = i;
    }
    build(root, 1, num);
    double area = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int l = indexs[Line[i].y1] + 1;
        int r = indexs[Line[i].y2] + 1;
        if (Line[i].s)
        {
            insert(root, l, r);
        }
        else
        {
            del(root, l, r);
        }
        area += root->m * (Line[i + 1].x - Line[i].x);
    }
    printf("%ld", (long long)area);
}
