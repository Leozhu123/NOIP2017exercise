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
const int maxn=10005;
struct Edge{
    int from,to,weight;
    Edge(int u, int v, int w) : from(u), to(v), weight(w){}
    bool operator<(const Edge &r) const{
        return weight > r.weight;
    }
};
vector<int> G[maxn];
int wei[maxn];
vector<Edge> edge;
int f[maxn];
int fa[maxn][25];
int dep[maxn];
int n, m, q;
int findfa(int x){
    return x == f[x] ? x : f[x] = findfa(f[x]);
}
void ae(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int x,int f){
    fa[x][0]=f;
    dep[x] = dep[f] + 1;
    for (int i = 1; i <= 20;i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = 0; i < G[x].size();i++){
        int v=G[x][i];
        if(v==f) continue;
        dfs(v, x);
    }
}
void kus(){
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= (n << 1);i++)
        f[i] = i;
    int cnt = n;
    for (int i = 0; i < edge.size(); i++){
        Edge &e = edge[i];
        int f1=findfa(e.from);
        int f2 = findfa(e.to);
        if(f1==f2)
            continue;
        cnt++;
        ae(f1, cnt);
        ae(f2, cnt);
        wei[cnt] = e.weight;
        f[f1] = cnt;
        f[f2] = cnt;
    }
    for (int i = cnt; i >= 1;i--){
        if(!dep[i])
            dfs(i, 0);
    }
}
int query(int u, int v){
    if(findfa(u)!=findfa(v))
        return -1;
    if(dep[u]>dep[v])
        swap(u, v);
    int delta=dep[v]-dep[u];
    for (int i = 0; i <= 20;i++){
        if(delta&(1<<i))
            v = fa[v][i];
    }
    //cout << u<<" "<<v << endl;
    if(u==v)
        return wei[v];
    for (int i = 20; i >= 0;i--){
        if(fa[u][i]!=fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return wei[fa[u][0]];
}
int main(){
    read(n, m);
    for (int i = 1; i <= m;i++){
        int u,v,w;
        read(u,v,w);
        edge.push_back(Edge(u, v, w));
    }
    kus();
    read(q);
    for (int i = 1; i <= q;i++){
        int u,v;
        read(u,v);
        printf("%d\n", query(u, v));
    }
}