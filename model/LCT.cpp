#include <cstdio>
#include <iostream>
using namespace std;
const long long maxn = 10;
const int maxn=300005;
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
	long long n, m;
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &da[i]);
		MakeTree(i);
	}
	for (long long i = 0; i < m; i++)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 0)
		{
			printf("%lld\n", ask(location[b], location[c]));
		}
		else if (a == 1)
		{
			if (FindRoot(location[b]) != FindRoot(location[c]))
			{
				Link(location[b], location[c]);
			}
		}
		else if (a == 2)
		{
			if (FindRoot(location[b]) == FindRoot(location[c]))
			{
				Cut(location[b], location[c]);
			}
		}
		else
		{
			change(b, c);
		}
	}
}
