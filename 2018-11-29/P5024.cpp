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
#include <set>
#include <cstdlib>
#define P pair<int,int>
#define LL long long
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
const LL INF=1LL<<60;
int fa[maxn][20],val[maxn],dep[maxn],n,q;
LL f[maxn][2],g[maxn][2],fh[maxn][20][2][2];
vector<int> G[maxn];
set<P> s;
char type[10];
void dfs(int x,int FA,int d){
	dep[x]=d;
	fa[x][0]=FA;
	f[x][1]=val[x];
	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if(v==FA) continue;
		dfs(v,x,d+1);
		f[x][0]+=f[v][1];
		f[x][1]+=min(f[v][0],f[v][1]);
	}
}
void dfs2(int x){
	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if(v==fa[x][0]) continue;
		g[v][0]=g[x][1]+f[x][1]-min(f[v][0],f[v][1]);
		g[v][1]=min(g[x][0]+f[x][0]-f[v][1],g[v][0]);
		dfs2(v);
	}
}
LL solve(int x,int a,int y,int b){
	if(dep[x]<dep[y]){
		swap(x,y);
		swap(a,b);
	}
	LL tx[2]={INF,INF};
	LL ty[2]={INF,INF};
	LL nx[2],ny[2];
	tx[a]=f[x][a],ty[b]=f[y][b];
	for(int i=19;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			nx[0]=nx[1]=INF;
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					nx[j]=min(nx[j],tx[k]+fh[x][i][k][j]);
			tx[0]=nx[0],tx[1]=nx[1],x=fa[x][i];
		}
	}
	if(x==y) return tx[b]+g[x][b];
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			nx[0]=nx[1]=ny[0]=ny[1]=INF;
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    nx[j]=min(nx[j],tx[k]+fh[x][i][k][j]);
                    ny[j]=min(ny[j],ty[k]+fh[y][i][k][j]);
                }
            }
            tx[0]=nx[0],tx[1]=nx[1],x=fa[x][i];
            ty[0]=ny[0],ty[1]=ny[1],y=fa[y][i];
		}
	}
	int lca=fa[x][0];
    LL ans0=f[lca][0]-f[x][1]-f[y][1]+tx[1]+ty[1]+g[lca][0];
    LL ans1=f[lca][1]-min(f[x][0],f[x][1])-min(f[y][0],f[y][1])+min(tx[0],tx[1])+min(ty[0],ty[1])+g[lca][1];
    return min(ans0,ans1);
}
int main(){
	read(n,q);
	scanf("%s",type);
	for(int i=1;i<=n;i++) read(val[i]);
	for(int i=1;i<=n-1;i++){
		int u,v;
		read(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
		s.insert(P(u,v));
		s.insert(P(v,u));
	}
	dfs(1,0,1);
	dfs2(1);
	for(int i=1;i<=n;i++){
		fh[i][0][0][0]=INF;
        fh[i][0][0][1]=f[fa[i][0]][1]-min(f[i][0],f[i][1]);
        fh[i][0][1][0]=f[fa[i][0]][0]-f[i][1];
        fh[i][0][1][1]=f[fa[i][0]][1]-min(f[i][0],f[i][1]);
	}
	for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            int tmp=fa[i][j-1];
            fa[i][j]=fa[tmp][j-1];
            for(int u=0;u<2;u++){
                for(int v=0;v<2;v++){
                    fh[i][j][u][v]=INF;
                    for(int w=0;w<2;w++)
                        fh[i][j][u][v]=min(fh[i][j][u][v],fh[i][j-1][u][w]+fh[tmp][j-1][w][v]);
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
    	int a,x,b,y;
        read(a,x,b,y);
        if(x==0 && y==0 && s.find(P(a,b))!=s.end()){
            puts("-1");
            continue;
        }
        printf("%lld\n",solve(a,x,b,y));
    }
}
