#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define LL long long
#define P pair<int, int>
using namespace std;
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
const int maxn = 1000005;
int rr[maxn],n,m;
struct Node{
    int x;
    int delta;
    Node *lch,*rch;
    Node(){
        x=delta=0;
        lch = rch = 0;
    }
    void update(){
        x = min(lch->x, rch->x);
    }
    void pushdown(){
        if(lch) lch->x+=delta;
        if(rch) rch->x+=delta;
        if(lch) lch->delta+=delta;
        if(rch) rch->delta+=delta;
        delta = 0;
    }
};
void build(Node *&curr,int l,int r){
    curr=new Node();
    if(l==r){
        curr->x = rr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(curr->lch,l,mid);
    build(curr->rch, mid + 1, r);
    curr->update();
}
void modify(Node *curr,int l,int r,int ml,int mr,int x){
    if(ml<=l && r<=mr){
        curr->delta+=x;
        curr->x+=x;
        return;
    }
    int mid=(l+r)>>1;
    curr->pushdown();
    if(ml<=mid)
        modify(curr->lch, l, mid, ml, mr, x);
    if(mr>=mid+1)
        modify(curr->rch, mid + 1, r, ml, mr, x);
    curr->update();
}
int qurry(Node *curr,int l,int r,int ml,int mr){
    if(ml<=l && r<=mr){
        return curr->x;
    }
    int mid=(l+r)>>1;
    int ans = 0;
    curr->pushdown();
    if(ml<=mid)
        ans=qurry(curr->lch, l, mid, ml, mr);
    if(mr>=mid+1)
        ans=min(ans,qurry(curr->rch, mid + 1, r, ml, mr));
    return ans;
}
Node *root;
int main(){
    read(n,m);
    for (int i = 1; i <= n;++i)
        read(rr[i]);
    build(root, 1, n);
    for(int i=1;i<=m;i++){
        int d,s,t;
        read(d,s,t);
        modify(root, 1, n, s, t, -d);
        if(root->x<0) {
            printf("%d\n%d", -1, i);
            return 0;
        }
    }
    puts("0");
}

