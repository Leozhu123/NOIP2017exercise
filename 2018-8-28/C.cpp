// luogu-judger-enable-o2
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
const long long maxn = 1000000;
using namespace std;
struct Node
{
    Node *lch, *rch;
    long long st, ed;
    long long maxx;
    long long ans;
    long long delta;
    Node(long long l, long long r) : st(l), ed(r)
    {
        lch = rch = 0;
        maxx = 0;
        delta = 0;
        ans=0;
    }
};
struct line
{
    long long x, y1, y2;
    bool s;
};
line Line[maxn];
long long num;
long long y[maxn], ty[maxn];
Node *root;
void build(Node *&curr, long long st, long long ed)
{
    curr = new Node(st, ed);
    if(st==ed){
    	curr->ans=y[curr->st-1];
	}
    if (st!=ed)
    {
        long long mid = (st + ed) >> 1;
        build(curr->lch, st, mid);
        build(curr->rch, mid+1, ed);
    }
}
void pushdown(Node * curr){
	curr->lch->maxx += curr->delta;
	curr->rch->maxx += curr->delta;
	curr->lch->delta+=curr->delta;
	curr->rch->delta+=curr->delta;
	curr->delta=0;
}
void update(Node *curr)
{
    if(curr->st==curr->ed){
        return;
    }
    if(curr->lch->maxx >= curr->rch->maxx){
        curr->maxx=curr->lch->maxx;
        curr->ans=curr->lch->ans;
    }else{
        curr->maxx=curr->rch->maxx;
        curr->ans=curr->rch->ans;
    }
}
void insert(Node *curr, long long st, long long ed)
{
    if (st <= curr->st && curr->ed <= ed)
    {
        curr->delta++;
        curr->maxx++;
        return;
    }
    long long mid = (curr->st + curr->ed) >> 1;
    pushdown(curr);
    if (st <= mid)
        insert(curr->lch, st, ed);
    if (ed > mid)
        insert(curr->rch, st, ed);
    update(curr);
}
void del(Node *curr, long long st, long long ed)
{
    if (st <= curr->st && curr->ed <= ed)
    {
        curr->delta--;
        curr->maxx--;
        return;
    }
    long long mid = (curr->st + curr->ed) >> 1;
    pushdown(curr);
    if (st <= mid)
        del(curr->lch, st, ed);
    if (ed > mid)
        del(curr->rch, st, ed);
    update(curr);
}
map<long long, long long> indexs;
bool cmp(line l1, line l2)
{
    return l1.x < l2.x || (l1.x==l2.x && l1.s==true);
}
int main()
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
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
    long long tn=n;
    n <<= 1;
    sort(Line, Line + n, cmp);
    sort(ty, ty + n);
    y[0] = ty[0];
    for (long long i = num = 1; i < n; i++)
    {
        if (ty[i] != ty[i - 1])
        {
            y[num++] = ty[i];
        }
    }
    for (long long i = 0; i < num; i++)
    {
        indexs[y[i]] = i;
    }
    build(root, 1, num);
    for (long long i = 0; i < n - 1; i++)
    {
        long long l = indexs[Line[i].y1] + 1;
        long long r = indexs[Line[i].y2] + 1;
        if (Line[i].s)
        {
            insert(root, l, r);
        }
        else
        {
            del(root, l, r);
        }
       // cout<<Line[i].x<<" "<<l<<" "<<r<<" "<<root->maxx<<endl;
        if(root->maxx>=tn-1){
            cout<<Line[i].x<<" "<<root->ans;
            return 0;
        }
    }
}
