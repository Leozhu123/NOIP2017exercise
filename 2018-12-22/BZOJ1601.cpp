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
const int maxn = 1005;
int fa[maxn];
int findfa(int x){
    return x == fa[x] ? x : fa[x] = findfa(fa[x]);
}
struct Edge{
    int u,v,c;
    Edge(int u,int v,int c):u(u),v(v),c(c){}
    bool operator<(const Edge &r) const{
        return c < r.c;
    }
};
int n, m;
int w[maxn];
vector<Edge> edges;
int main(){
    read(n);
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }
    for(int i=1;i<=n;i++){
		int x;
		read(x);
        edges.push_back(n+1,i,x);
    }
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int x;
			read(x);
			if(i==j) continue;
			edges.push_back(i,j,x);
		}
    sort(edges.begin(), edges.end());
    int cnt = 0;
    int ans = 0;
	n++;
    for (int i = 0;i<edges.size();i++){
        Edge &e=edges[i];
        int fa1 = findfa(e.u);
        int fa2 = findfa(e.v);
        if(fa1==fa2)
            continue;
        ans += e.c;
        fa[fa1]=fa2;
        cnt++;
        if(cnt==n-1)
            break;
    }
    printf("%d", ans);
}
