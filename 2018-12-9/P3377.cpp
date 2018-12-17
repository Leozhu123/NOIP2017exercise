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
int lch[maxn],rch[maxn],dist[maxn],key[maxn],fa[maxn];
int merge(int a,int b){
    if(a==0 || b==0) return a+b;
    if(key[a]>key[b] || (key[a]==key[b] && a>b) ) swap(a,b);
    rch[a]=merge(rch[a],b);
    fa[rch[a]]=a;
    if(dist[rch[a]]>dist[lch[a]]) swap(lch[a],rch[a]);
    dist[a]=dist[rch[a]]+1;
    return a;
}
int findfa(int x){
    if(fa[x]) return findfa(fa[x]);
    return x;
}
int main(){
    int n,m;
    read(n,m);
    dist[0]=-1;
    for(int i=1;i<=n;i++){
        read(key[i]);
    }
    for(int i=1;i<=m;i++){
        int opt,x,y;
        read(opt);
        if(opt==1){
            read(x,y);
            if(key[x]==-1 || key[y]==-1) continue;
            if(x==y) continue;
			x=findfa(x),y=findfa(y);
            merge(x,y);
        }else{
            read(x);
            if(key[x]==-1) {
            	puts("-1");
            	continue;
        	}
            x=findfa(x);
            printf("%d\n",key[x]);
            key[x]=-1;
            fa[lch[x]]=fa[rch[x]]=0;
            merge(lch[x],rch[x]);
        }
    }
}






 
