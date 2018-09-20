#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;
#define P pair<int,int>
const int maxn = 100005;
const int inf = (1 << 30) - 1;
struct edge{
    int u,v,w;
    edge(int u,int v ,int w):u(u),v(v),w(w){}
};
vector<edge> G[maxn],rG[maxn];
int dis[maxn];
int f[maxn][55];
bool ins[maxn][55];
int n,m,k,p;
struct cmp{
    bool operator()(const P &l,const P &r){
        return l.second > r.second;
    }
};
void Dij(){
    priority_queue<P ,vector<P >,cmp> q;
    dis[n]=0;
    q.push(P(n,0));
    while(!q.empty()){
        P x=q.top();
        q.pop();
        int u = x.first;
        if(dis[u]<x.second) continue;
        for(int i=0;i<rG[u].size();i++){
            edge &e = rG[u][i];
            if(dis[e.v]>dis[e.u]+e.w) {
                dis[e.v]=dis[e.u]+e.w;
                q.push(P(e.v, dis[e.v]));
            }
        }
    }
}

int dfs(int x,int t){
    if(ins[x][t]) return -1;
    if(f[x][t])
        return f[x][t];
    ins[x][t]=1;
    f[x][t] = (x == n);
    for(int i=0;i<G[x].size();i++){
        edge &e = G[x][i];
        int r = dis[x] + t - e.w - dis[e.v];
        if (r < 0 || r > k) continue;
        int ret = dfs(e.v, r);
        if (ret!=-1) f[x][t] += ret;
        else return -1;
        while (f[x][t] >= p) f[x][t] -= p;
    }
    ins[x][t] = 0;
    return f[x][t];
}
void init(){
    for(int i=1;i<=n;i++){
        dis[i]=inf;
        G[i].clear();
        rG[i].clear();
        for (int j = 0; j <= k;j++){
            f[i][j] = 0;
            ins[i][j] = false;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>p;
        init();
        for(int i=1;i<=m;i++){
            int u,v,c;
            cin>>u>>v>>c;
            G[u].push_back(edge(u, v, c));
            rG[v].push_back(edge(v, u, c));
        }
        Dij();
    //    for(int i=1;i<=n;i++){
    //        cout << dis[i] << " ";
    //    }
     //   cout << endl;
        int ans=dfs(1,k);
        if(ans==-1){
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}