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
const int maxn=400005;
struct Edge{
    int u,v,l,a;
    Edge(int u,int v,int l,int a):u(u),v(v),l(l),a(a){}
    bool operator<(const Edge &r) const{
        return a > r.a;
    }
};
int n,m;
vector<Edge> G[maxn];
vector<int> G2[maxn];
vector<Edge> edge;
int dep[maxn];
int f[maxn];
int fa[maxn][20];
int p[maxn];
int dis[maxn];
int LOG;
int findfa(int x){
    return x == f[x] ? x : f[x]=findfa(f[x]);
}
void init(){
    memset(fa,0,sizeof(fa));
    memset(p, 0, sizeof(p));
    for(int i=0;i<(n<<1);i++){
        f[i] = i;
        dis[i] = INT_MAX;
        G[i].clear();
        G2[i].clear();
    }
    edge.clear();
}
void dij(){
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(0, 1));
    dis[1]=0;
    while(!q.empty()){
        P x=q.top();
        q.pop();
        if(dis[x.second]<x.first)
            continue;
        for(int i=0;i<G[x.second].size();i++){
            Edge &e = G[x.second][i];
            if(dis[e.v]>dis[x.second]+e.l){
                dis[e.v]=dis[x.second]+e.l;
                q.push(P(dis[e.v], e.v));
            }
        }
    }
}
void dfs(int x,int f){
    dep[x]=dep[f]+1;
    fa[x][0] = f;
    for(int i=1;i<=LOG;i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<G2[x].size();i++){
        int v=G2[x][i];
        if(v==f) continue;
        dfs(v,x);
        dis[x] = min(dis[x], dis[v]);
    }
}
void ae(int u,int v){
    G2[u].push_back(v);
    G2[v].push_back(u);
}
void kus(){
    int tot = 0;
    int cnt = n;
    sort(edge.begin(), edge.end());
    for(int i=0;i<edge.size();i++){
        Edge &e=edge[i];
        if(findfa(e.u)==findfa(e.v))
            continue;
        cnt++;
        ae(cnt,findfa(e.u));
        ae(cnt, findfa(e.v));
        f[findfa(e.u)]=cnt;
        f[findfa(e.v)]=cnt;
        p[cnt] = e.a;
        tot++;
        if(tot==n-1)
            break;
    }
    dfs(cnt, 0);
}
int query(int v,int pp){
    for(int i=LOG;i>=0;i--){
        if((dep[v]-(1<<i)>0) && p[fa[v][i]]>pp){
            v = fa[v][i];
        }
    }
    return dis[v];
}
int main(){
    int T;
    read(T);
    while(T--){
        read(n, m);
        while((1<<LOG)<n)
            LOG++;
        init();
        for(int i=1;i<=m;i++){
            int u,v,l,a;
            read(u,v,l,a);
            G[u].push_back(Edge(u,v,l,a));
            G[v].push_back(Edge(v,u,l,a));
            edge.push_back(Edge(u, v, l, a));
        }
        dij();
        kus();
        int Q,K,S;
        read(Q,K,S);
        int lastans=0;
        for(int i=1;i<=Q;i++){
            int v,p;
            read(v,p);
            v = (v + K * lastans - 1) % n + 1;
            p = (p + K * lastans) % (S + 1);
            printf("%d\n", lastans = query(v, p));
        }
    }
}