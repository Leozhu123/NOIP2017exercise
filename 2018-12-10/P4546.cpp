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
#define LD long double
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
int fa[maxn],ch[maxn][2];
int type[maxn];
LD point[maxn][13],pre[maxn][13],a[maxn],b[maxn];
int rev[maxn];
char s[20];
inline LD calc(int type,int n,LD a,LD b){
	LD sum=0;
	switch(type){
		case 1:
			switch(n & 3){
				case 0:
					sum = sin(0.5 * a + b);
					break;
				case 1:
					sum = cos(0.5 * a + b);
					break;
				case 2:
					sum = -sin(0.5 * a + b);
					break;
				case 3:
					sum = -cos(0.5 * a + b);
					break;
			}
			return sum * pow(a , n);
		case 2:
			return pow(a , n) * exp(a * 0.5 + b);
		case 3:
			switch(n){
				case 0:
					return a * 0.5 + b;
				case 1:
					return a;
				default:
					return 0;
			}
	}
}
inline int idon(int x){
	if(x==ch[fa[x]][0]) return 0;
	if(x==ch[fa[x]][1]) return 1;
	return -1;
}
inline void update(int x){
	for(int i=0;i<=12;i++){
		point[x][i]=pre[x][i]+point[ch[x][0]][i]+point[ch[x][1]][i];
	}
}
inline void getpre(int x){
	for(int i=0;i<=12;i++)
		pre[x][i]=calc(type[x],i,a[x],b[x]);
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
inline void change(int x,int t,LD aa,LD bb){
	access(x);
	splay(x);
	type[x]=t;
	a[x]=aa;
	b[x]=bb;
	getpre(x);
	update(x);
}
int main()
{
    int n,m;
    read(n,m);
    scanf("%s" , s);
    for(int i=1;i<=n;i++){
		read(type[i]);
		scanf("%Lf %Lf",a+i,b+i);
		getpre(i);
	}
    for(int i=1;i<=m;i++){
        LD a , b , times , jc;
        int d , e;
        if(scanf("%s" , s) == EOF)
            return 0;
        switch(s[0]){
        case 'a':
            read(d,e);
			d++;e++;
            link(d , e);
            break;
        case 'd':
            read(d,e);
			d++;e++;
            cut(d , e);
            break;
        case 'm':
            read(d,e);
			d++;
            scanf("%Lf %Lf" , &a , &b);
            change(d , e , a , b);
            break;
        case 't':
            read(d,e);
			d++;e++;
            scanf("%Lf" , &a);
            if(frt(d) != frt(e))
                puts("unreachable");
            else{
                split(d , e);
                b = 0;
                times = jc = 1;
                a -= 0.5;
                for(int i = 0 ; i <= 12 ; ++i){
                    b += times * point[e][i] / jc;
                    times *= a;
                    jc *= (i + 1);
                }
                printf("%.9Lf\n" , b);
            }
        }
    }
    return 0;
}
