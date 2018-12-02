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
const int maxn=200005;
int lch[maxn<<6],rch[maxn<<6];
int x[maxn<<6];
int tot;
void modify(int &cur,int old,int l,int r,int a){
    if(cur==0) cur=++tot,x[cur]=x[old]+1;
    else x[cur]++;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(a<=mid) rch[cur]=rch[old],modify(lch[cur],lch[old],l,mid,a);
    else lch[cur]=lch[old],modify(rch[cur],rch[old],mid+1,r,a);
}
int qurry(int st,int ed,int l,int r,int k){
    if(l==r) return l;
    int s=x[lch[ed]]-x[lch[st]];
    int mid = (l + r) >> 1;
    if(k<=s){
        return qurry(lch[st],lch[ed],l,mid,k);
    }else{
        return qurry(rch[st], rch[ed], mid + 1, r, k - s);
    }
}
int root[maxn];
int main(){
    int n,m;
    read(n,m);
    for(int i=1;i<=n;i++){
        int x;
        read(x);
        modify(root[i],root[i-1],-1e9,1e9,x);
    }
    for(int i=1;i<=m;i++){
        int l,r,k;
        read(l,r,k);
        printf("%d\n", qurry(root[l - 1], root[r], -1e9, 1e9, k));
    }
}