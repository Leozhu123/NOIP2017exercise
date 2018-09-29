#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 300009;
const int maxm = 600009;
int n, m;
int w[maxn], spn[maxm], bucket[maxn+maxm], ans[maxn];
vector<int> v1[maxm], v2[maxm], v3[maxm];
struct person{
    int u, v, dis, lca;
};
person p[maxn];
vector<int> G[maxn];
void ae(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
int deep[maxn],f[maxn][25];
bool vis[maxn];
void dfs(int x,int dep){
    vis[x]=true;
    deep[x] = dep;
    for (int i = 1; i <= 22;i++){
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(vis[v]) continue;
        f[v][0]=x;
        dfs(v, dep + 1);
    }
    vis[x] = false;
}
int jump(int u,int step){
    for (int i = 0;i<=22;i++){
        if((step&(1<<i)))
            u = f[u][i];
    }
    return u;
}
int lca(int u,int v){
    if(deep[u]<deep[v]) swap(u,v);
    u = jump(u,deep[u] - deep[v]);
    for (int i = 22; i >= 0;i--){
        if(f[u][i]!=f[v][i])
            u = f[u][i], v = f[v][i];
    }
    return u == v ? u : f[u][0];
}
void dfs1(int x){
    vis[x]=true;
    int prev = bucket[deep[x] + w[x] + maxn];
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(!vis[v])
            dfs1(v);
    }
    bucket[deep[x] + maxn] += spn[x];
    ans[x] += bucket[deep[x] + w[x] + maxn] - prev;
    for(int i=0;i<v1[x].size();i++){
        bucket[deep[v1[x][i]] + maxn]--;
    }
    vis[x] = false;
}
void dfs2(int x){
    vis[x]=true;
    int prev = bucket[w[x] - deep[x] + maxn];
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(!vis[v])
            dfs2(v);
    }
    for (int i = 0;i<v2[x].size();i++){
        bucket[v2[x][i] + maxn]++;
    }
        ans[x] += bucket[w[x] - deep[x] + maxn] - prev;
    for(int i=0;i<v3[x].size();i++){
        bucket[v3[x][i] + maxn]--;
    }
    vis[x] = false;
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n - 1;i++){
        int u,v;
        cin>>u>>v;
        ae(u, v);
    }
    for(int i=1;i<=n;i++)
        cin >> w[i];
    f[1][0] = 0;
    dfs(1, 0);
    for (int i = 1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        p[i].u = u;
        p[i].v = v;
        p[i].lca = lca(u, v);
        p[i].dis = deep[u] + deep[v] - 2 * deep[p[i].lca];
        spn[u]++;
        v1[p[i].lca].push_back(u);
        v2[v].push_back(p[i].dis-deep[p[i].v]);
        v3[p[i].lca].push_back(p[i].dis-deep[p[i].v]);
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=m;i++){
        if(deep[p[i].u] == deep[p[i].lca]+w[p[i].lca]) ans[p[i].lca]--;
    }
    for (int i = 1; i <= n;i++){
        cout << ans[i] << " ";
    }
}