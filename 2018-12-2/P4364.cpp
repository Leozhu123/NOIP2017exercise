#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
#define P system("pause");
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
int nxt[maxn];
int fa[maxn], size[maxn],ans[maxn];
int bit[maxn];
int a[maxn];
int n;
inline int lowbit(int x){
	return x&-x;
}
void add(int x,int a){
	while(x<=n){
		bit[x]+=a;
		x+=lowbit(x);	
	}	
}
int sum(int x){
	int ret=0;
	while(x) {
		ret+=bit[x];
		x-=lowbit(x);
	}
	return ret;
}
int qurry(int x){
	int l=1,r;
	for(r=1;r<n;r<<=1);
	while(l<r){
		int mid=(l+r)>>1;
		if(bit[mid]>=x) r=mid;
		else x-=bit[mid],l=mid+1;
	}
	return l;
}
double k;
int root;
int main(){
    read(n);
    cin >> k;
    for(int i=1;i<=n;i++) read(a[i]),add(i,1);
    sort(a+1,a+n+1,greater<int>());
    for(int i=n-1;i>=1;i--)
        if(a[i]==a[i+1])
            nxt[i] = nxt[i + 1] + 1;
    for(int i=1;i<=n;i++)
        fa[i]=int(i/k),size[i]=1;
    for(int i=n;i>=1;i--) 
        size[fa[i]]+=size[i];
    for(int i=1;i<=n;i++){
        if(fa[i]!=fa[i-1])
            add(ans[fa[i]], size[fa[i]]-1),add(n+1, -(size[fa[i]]-1));
        int p=qurry(size[i]);
        p += nxt[p];nxt[p]++;p-=nxt[p]-1;ans[i]=p;
        add(p, -size[i]);
        add(n+1,size[i]);
    }
    for(int i=1;i<=n;i++)
        printf("%d ", a[ans[i]]);
}
