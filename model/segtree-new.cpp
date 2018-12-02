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
const int maxn=100005;
int lch[maxn<<2],rch[maxn<<2];
LL delta[maxn<<2],x[maxn<<2];
LL a[maxn];
int tot;
void update(int cur){
    x[cur] = x[lch[cur]] + x[rch[cur]];
}
void pushdown(int cur,int l,int r){
    int mid=(l+r)>>1;
    if(delta[cur]){
        x[lch[cur]]+=(mid-l+1)*delta[cur];
        x[rch[cur]]+=(r-mid)*delta[cur];
        delta[lch[cur]]+=delta[cur];
        delta[rch[cur]]+=delta[cur];
        delta[cur]=0;
    }
}
void build(int &cur,int l,int r){
    cur=++tot;
    if(l==r){
        x[cur]=a[l];
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
        x[cur]+=a*(r-l+1);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(cur,l,r);
    if(ml<=mid) modify(lch[cur],l,mid,ml,mr,a);
    if(mr>=mid+1) modify(rch[cur],mid+1,r,ml,mr,a);
    update(cur);
}
LL qurry(int cur,int l,int r,int ml,int mr){
    LL ans=0;
    if(ml<=l && r<=mr){
        return x[cur];
    }
    int mid=(l+r)>>1;
    pushdown(cur,l,r);
    if(ml<=mid) ans+=qurry(lch[cur],l,mid,ml,mr);
    if(mr>=mid+1) ans+=qurry(rch[cur],mid+1,r,ml,mr);
    return ans;
}
int n,m;
int root;
int main(){
    read(n,m);
    for(int i=1;i<=n;i++) read(a[i]);
    build(root,1,n);
    for(int i=1;i<=m;i++){
        int t,x,y;
        read(t,x,y);
        if(t==1){
            int k;
            read(k);
            modify(root,1,n,x,y,k);
        }else{
            printf("%lld\n",qurry(root,1,n,x,y));
        }
    }
}