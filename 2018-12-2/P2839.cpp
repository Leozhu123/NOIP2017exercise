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
#include <cstdlib>
#define LL long long
#define P system("pause")
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
struct Mx{
    int lmax, rmax, sum;
    void init(){
        lmax = rmax = -maxn, sum = 0;
    }
};
Mx ans;
int lch[maxn<<5],rch[maxn<<5];
int id[maxn];
int rt[maxn];
int a[maxn];
Mx v[maxn<<5];
int q[4];
int tot;
Mx merge(Mx a,Mx b){
	Mx c;
    c.lmax = max(a.lmax, a.sum + b.lmax);
    c.rmax = max(b.rmax, a.rmax + b.sum);
    c.sum = a.sum + b.sum;
    return c;
}
void build(int &cur,int l,int r){
	cur=++tot;
	v[cur].lmax=v[cur].rmax=v[cur].sum=r-l+1;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lch[cur],l,mid);
	build(rch[cur],mid+1,r);
}
void modify(int &x,int l,int r,int a){
    tot++;
	v[tot]=v[x],lch[tot]=lch[x],rch[tot]=rch[x],x=tot;
    if(l==r){
    	v[x].lmax=v[x].rmax=v[x].sum=-1;
    	return;
	}
    int mid=(l+r)>>1;
    if(a<=mid) modify(lch[x],l,mid,a);
    else modify(rch[x],mid+1,r,a);
    v[x]=merge(v[lch[x]],v[rch[x]]);
}
void qurry(int cur,int l,int r,int ml,int mr){
	if(ml <= l && r<=mr){
        ans = merge(ans, v[cur]);
        return;
    }
    int mid = (l + r) >> 1;
    if(ml <= mid) qurry(lch[cur], l, mid, ml, mr);
    if(mr > mid) qurry(rch[cur], mid + 1, r, ml, mr);
}
int n,m;
bool chk(int mid){
	int val = 0;
    if(q[1] + 1 <= q[2] - 1) ans.init(), qurry(rt[mid], 1, n, q[1] + 1, q[2] - 1), val += ans.sum;
    ans.init(), qurry(rt[mid], 1, n, q[0], q[1]), val += ans.rmax;
    ans.init(), qurry(rt[mid], 1, n, q[2], q[3]), val += ans.lmax;
    return val >= 0;
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
    read(n);
    build(rt[1],1,n);
    v[0].init();
    for(int i=1;i<=n;i++) read(a[i]),id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=2;i<=n;i++) rt[i]=rt[i-1],modify(rt[i],1,n,id[i-1]);
    read(m);
    int lastans=0;
    for(int i=1;i<=m;i++){
    	for(int i=0;i<4;i++){
    		read(q[i]);
    		q[i]=(q[i]+lastans)%n+1;
		}
		sort(q,q+4);
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(chk(mid)) lastans=a[id[mid]],l=mid+1;
			else r=mid-1;
		}
		cout<<lastans<<endl;
	}
}
