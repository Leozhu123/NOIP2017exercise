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
const int maxn=30005;
int fa[maxn],ch[maxn][2],s[maxn],v[maxn];
int rev[maxn];
inline int idon(int x){
	if(x==ch[fa[x]][0]) return 0;
	if(x==ch[fa[x]][1]) return 1;
	return -1;
}
inline void update(int x){
	s[x]=s[ch[x][0]]^s[ch[x][1]]^v[x];
}
inline void pushd(int x){
	if(rev[x]){
		swap(ch[x][0],ch[x][1]);
		rev[ch[x][0]]^=1;
		rev[ch[x][1]]^=1;
		rev[x]=0;
	}
}
inline void rotate(int x){
	int y=fa[x],d=idon(x);
	if(idon(y)!=-1) ch[fa[y]][idon(y)]=x;
	fa[x]=fa[y];
	ch[y][d]=ch[x][d^1];fa[ch[y][d]]=y;
	ch[x][d^1]=y;fa[y]=x;
	update(y);
	update(x);
}
void mt(int x){
	if(idon(x)!=-1) mt(fa[x]);
	pushd(x);
}
inline void splay(int x){
	mt(x);
	while(idon(x)!=-1) rotate(x);
}
inline void access(int x){
	for(int y=0;x;y=x,x=fa[x]){
		splay(x);
		ch[x][1]=y;
		update(x);
	}
} 
inline void mkrt(int x){
	access(x);
	splay(x);
	rev[x]^=1;
	pushd(x);
}
inline int frt(int x){
	access(x);
	splay(x);
	while(ch[x][0]) x=ch[x][0];
	return x;
}
inline void split(int x,int y){
	mkrt(x);
	access(y);
	splay(y);
}
inline void link(int x,int y){
    mkrt(x);
    if(frt(y)!=x) fa[x]=y;
}
inline void cut(int x,int y){
	mkrt(x);
    if(frt(y)==x && fa[x]==y && !ch[x][1]){
        fa[x]=ch[y][0]=0;
        update(y);
    }
}
int main()
{
    int n,m,type,x,y;
    read(n,m);
    for(int i=1;i<=n;i++){
		read(v[i]);
	}
    for(int i=1;i<=m;i++){
        read(type,x,y);
        switch(type){
        	case 0:split(x,y);printf("%d\n",s[y]);break;
        	case 1:link(x,y);break;
        	case 2:cut(x,y);break;
        	case 3:splay(x);v[x]=y;update(x);
        }
    }
    return 0;
}
