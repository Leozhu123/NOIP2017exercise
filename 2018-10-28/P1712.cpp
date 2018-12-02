#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
#define P pair<int,int>
using namespace std;
const int maxn = 1000005;
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
struct Node{
    int x,delta;
    Node *lch,*rch;
    Node(){
        x=delta=0;
        lch = rch = 0;
    }
    void pushdown(){
        lch->x+=delta;
        rch->x+=delta;
        lch->delta+=delta;
        rch->delta+=delta;
        delta = 0;
    }
    void update(){
        x = max(lch->x, rch->x);
    }
};
int a[maxn];
void build(Node *&curr,int l,int r){
    curr=new Node();
    if(l==r) {
        curr->x = 0;
        return;
    }
    int mid=(l+r)>>1;
    build(curr->lch,l,mid);
    build(curr->rch,mid+1,r);
    curr->update();
}
void modify(Node *curr,int l,int r,int ml,int mr,int x){
    if(ml<=l && r<=mr){
        curr->delta+=x;
        curr->x += x;
        return;
    }
    int mid=(l+r)>>1;
    curr->pushdown();
    if(ml<=mid) 
        modify(curr->lch,l,mid,ml,mr,x);
    if(mr>=mid+1)
        modify(curr->rch, mid + 1, r, ml, mr, x);
    curr->update();
}
struct Seg{
    int l,r,nl,nr;
    int len;
    bool operator<(const Seg &r)const{
        return len < r.len;
    } 
};
Seg segs[maxn];
int n, m;
int cnt = 0;
int main(){
    read(n,m);
    for(int i=1;i<=n;i++){
        read(segs[i].l,segs[i].r);
        segs[i].len = segs[i].r - segs[i].l + 1;
        a[(i - 1) * 2] = segs[i].l;
        a[(i - 1) * 2 + 1] = segs[i].r;
    }
    sort(a, a + 2*n);
    cnt = unique(a, a + 2 * n) - a;
    sort(segs + 1, segs + n + 1);
    Node *root;
    build(root, 1, cnt);
    int r = 2;
    int ans = INT_MAX;
    modify(root, 1, cnt, lower_bound(a, a + cnt, segs[1].l)-a+1, lower_bound(a, a + cnt, segs[1].r)-a+1, 1);
    for(int l=1;l<=n;l++){
        while(root->x<m && r<=n){
            modify(root, 1, cnt, lower_bound(a, a + cnt, segs[r].l)-a+1, lower_bound(a, a + cnt, segs[r].r)-a+1, 1);
            r++;
        }
        if(r>n)
            break;
        ans = min(ans, segs[r-1].len - segs[l].len);
        modify(root, 1, cnt, lower_bound(a, a + cnt, segs[l].l)-a+1, lower_bound(a, a + cnt, segs[l].r)-a+1, -1);
    }
    if(ans==INT_MAX)
        puts("-1");
    else 
        printf("%d", ans);
}
