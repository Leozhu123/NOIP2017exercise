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
int f[maxn];
int fa[maxn][25];
int wei[maxn][25];
bool vis[maxn];
int dep[maxn];
struct Edge{
    int from,to,weight;
    Edge(int u,int v,int w):from(u),to(v),weight(w){}
    bool operator<(Edge & e)const{
        return weight > e.weight;
    }
};
int findfa(int x){
    return x == f[x] ? x : findfa(f[x]);
}
vector<Edge> edges;
vector<Edge> G[maxn];
int q;
int n, m;
int LOG;
void kruskal(){
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        Edge &e = edges[i];
        if(findfa(e.from)==findfa(e.to)) continue;
        G[e.from].push_back(Edge(e.from,e.to,e.weight));
        G[e.to].push_back(Edge(e.to, e.from, e.weight));
        f[findfa(e.from)] = findfa(e.to);
    }
}
void dfs(int x,int f,int w,int d){
    fa[x][0]=f;
    wei[x][0]=w;
    dep[x] = d;
    vis[x] = true;
    for(int i=1;i<=LOG;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
        wei[x][i] = min(wei[fa[x][i - 1]][i - 1], wei[x][i - 1]);
    }
    for(int i=0;i<G[x].size();i++){
        Edge &e=G[x][i];
        if(e.to==f)
            continue;
        dfs(e.to, x, e.weight,d+1);
    }
}
int calc(int x,int y){
    if(findfa(x)!=findfa(y))
        return -1;
    if(dep[x]>dep[y])
        swap(x, y);
    int delta = dep[y] - dep[x];
    int ans = INT_MAX;
    for (int i = 0; i < LOG;i++){
        if(delta&(1<<i)) {
            ans = min(ans, wei[y][i]);
            y = fa[y][i];
        }
    }
    if(x==y){
        return ans;
    }
    for (int i = LOG;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            ans=min(ans,wei[x][i]);
            ans=min(ans,wei[y][i]);
            x=fa[x][i];
            y = fa[y][i];
        }
    }
    if(x==y){
        return ans;
    }else{
        return min(ans, min(wei[x][0], wei[y][0]));
    }
}
int main(){
    read(n, m);
    while((1<<LOG)<=n)
        LOG++;
    for(int i=1;i<=n;i++)
        f[i] = i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        read(u, v, w);
        edges.push_back(Edge(u,v,w));
    }
    kruskal();
    wei[0][0] = INT_MAX;
    for(int i=1;i<=n;i++){
        if(!vis[i])
            dfs(i, 0, INT_MAX,0);
    }
    read(q);
    for(int i=1;i<=q;i++){
        int u,v;
        read(u, v);
        printf("%d\n", calc(u, v));
    }
}
