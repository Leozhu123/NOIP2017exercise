#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define LL long long
const int maxn = 50005;
int a[maxn];
int pos[maxn];
struct Query{
    int l, r, id;
    LL a;
    friend bool operator < (const Query &R,const Query &T) 
    {
        return pos[R.l]<pos[T.l] || (pos[R.l]==pos[T.l] && R.r<T.r);
    }
};
Query Q[maxn];
int times[maxn];
int n, m,k;
using namespace std;
void modify(int x,LL&ans ,int add){
    ans -= times[a[x]] * times[a[x]];
    times[a[x]]+=add;
    ans += times[a[x]] * times[a[x]];
}
bool cmp_id(const Query &a,const Query &b)
{
    return a.id<b.id;
}

void init()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int limit=(int)sqrt((double)n+0.5);
    for(int i=1;i<=n;++i)
        pos[i]=(i-1)/limit+1;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    sort(Q+1,Q+m+1);
}
void solve(){
    LL ans = 0;
    int l=1;
    int r=0;
    for(int i=1;i<=m;++i)
    {
        if(r<Q[i].r)
        {
            for(r=r+1;r<Q[i].r;++r)
                modify(r,ans,1);
            modify(r,ans,1);
        }
        if(Q[i].l<l)
        {
            for(l=l-1;Q[i].l<l;--l)
                modify(l,ans,1);
            modify(l,ans,1);
        }
        if(Q[i].r<r)
            for(;Q[i].r<r;--r)
                modify(r,ans,-1);
        if(l<Q[i].l)
            for(;l<Q[i].l;++l)
                modify(l,ans,-1);
        Q[i].a=ans;
    }
    sort(Q+1,Q+m+1,cmp_id);
    for(int i=1;i<=m;++i)
        printf("%lld\n",Q[i].a);
}
int main(){
    init();
    solve();
}