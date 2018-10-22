#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

#define P pair<int,int>
#define LL long long
using namespace std;
const int maxn=50005;
const int log=20;
vector<P > G[maxn];
vector<int> army;
vector<P > rest;
vector<P > 
int dis[maxn][log+5];
int fa[maxn][log+5];

void dfs(int x,int f,int d){
    dis[x][0]=d;
    fa[x][0]=f;
    for(int i=1;i<=log;i++){
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        dis[x][i] = dis[fa[x][i - 1]][i - 1] + dis[x][i - 1];
    }
    for(int i=0;i<G[x].size();i++){
        if (G[x][i].first==f)
            continue;
        dfs(G[x][i].first, G[x][i].second, x);
    }
}
bool check(int x){
    for(int i=0;i<army.size();i++){
        int now = army[i];
        int diss = 0;
        int pos = now;
        for(j=log;j>=0;j--){
            if(fa[pos][j]>1 && diss+dis[pos][j]<=x){
                diss=diss+dis[pos][j];
                pos = fa[pos][j];
            }
        }
        if(fa[pos][0]==1 && diss+dis[pos][0]<=x){
            rest.push_back(P(x - diss - dis[pos][0]), i);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(P(v,w));
        G[v].push_back(P(u,w));
    }
    int m;
    cin>>m;
    dfs(1,1,0);
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        army.push_back(x);
    }
}