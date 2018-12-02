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
const int maxn=500005;
int lch[maxn<<2],rch[maxn<<2];
int delta[maxn<<2],x[maxn<<2];
int a[maxn],nxt[maxn];
int fa[maxn], size[maxn],ans[maxn];
int tot;
void update(int cur){
    x[cur] = min(x[lch[cur]] , x[rch[cur]]);
}
void pushdown(int cur,int l,int r){
    if(delta[cur]){
        x[lch[cur]]+=delta[cur];
        x[rch[cur]]+=delta[cur];
        delta[lch[cur]]+=delta[cur];
        delta[rch[cur]]+=delta[cur];
        delta[cur]=0;
    }
}
void build(int &cur,int l,int r){
    cur=++tot;
    if(l==r){
        x[cur]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(lch[cur],l,mid);
    build(rch[cur],mid+1,r);
    update(cur);
}
void modify(int cur,int l,int r,int ml,int mr,int a){
    if(ml<=l && r<=mr){
        delta[cur]+=a;
        x[cur]+=a;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(cur,l,r);
    if(ml<=mid) modify(lch[cur],l,mid,ml,mr,a);
    if(mr>=mid+1) modify(rch[cur],mid+1,r,ml,mr,a);
    update(cur);
}
int qurry(int cur,int l,int r,int d){
    if(l==r) return l+(x[cur]<d);
    pushdown(cur,l,r);
    int mid = (l + r) >> 1;
    if(d<=x[rch[cur]])
        return qurry(lch[cur], l, mid, d);
    else
        return qurry(rch[cur], mid + 1, r, d);
}
int n;
double k;
int root;
int main(){
    read(n);
    cin >> k;
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1,greater<int>());
    for(int i=n-1;i>=1;i--)
        if(a[i]==a[i+1])
            nxt[i] = nxt[i + 1] + 1;
    for(int i=1;i<=n;i++)
        fa[i]=int(i/k),size[i]=1;
    for(int i=n;i>=1;i--) 
        size[fa[i]]+=size[i];
    build(root,1,n);
    for(int i=1;i<=n;i++){
        if(fa[i]!=fa[i-1])
            modify(root, 1, n, ans[fa[i]], n, size[fa[i]]-1);
        int p=qurry(root,1,n,size[i]);
        p += nxt[p];nxt[p]++;p-=nxt[p]-1;ans[i]=p;
        modify(root, 1, n, p, n, -size[i]);
    }
    for(int i=1;i<=n;i++)
        printf("%d ", a[ans[i]]);
}