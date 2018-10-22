#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
const int maxn = 100005;
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
struct Edge{
    int u,v,w;
    Edge(int u,int v,int w):u(u),v(v),w(w){}
};
int n,m;
int dis[maxn];
bool vis[maxn];
vector<Edge> G[maxn];
bool spfa(int u){
    vis[u] = true;
    for (int i = 0; i < G[u].size();i++){
        Edge &e = G[u][i];
        if(dis[e.v]<dis[u]+e.w){
            dis[e.v]=dis[u]+e.w;
            if(vis[e.v])
                return false;
            if(!spfa(e.v))
                return false;
        }
    }
    vis[u]=false;
    return true;
}
int main(){
    read(n,m);
    for(int i=1;i<=m;i++){
        int f,a,b,c;
        read(f,a,b);
        if(f==1){
            read(c);
            G[b].push_back(Edge(b, a, c));
        }
        if(f==2){
            read(c);
            G[a].push_back(Edge(a, b, -c));
        }
        if(f==3){
            G[a].push_back(Edge(a, b, 0));
            G[b].push_back(Edge(b, a, 0));
        }
    }
    for(int i=1;i<=n;i++){
        G[0].push_back(Edge(0,i,0));
        dis[i] = -INT_MAX;
    }
    if(!spfa(0)) 
        puts("No");
    else
        puts("Yes");
}