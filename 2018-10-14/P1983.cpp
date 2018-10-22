#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define P pair<int,int>
using namespace std;
const int maxn = 1005;
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
vector<int> G[maxn];
bool hasedge[maxn][maxn];
bool vis[maxn];
int n,m;
int s[maxn][maxn];
int du[maxn];
int ans = 0;
void bfs(){
    queue<P> q;
    for(int i=1;i<=n;i++){
        if(du[i]==0){
            q.push(P(i, 1));
        }
    }
    ans=1;
    while(!q.empty()){
        P x=q.front();
        q.pop();
        int u=x.first,val=x.second;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            du[v]--;
            if(du[v]==0){
                q.push(P(v, val + 1));
                ans=max(ans,val+1);
            }
        }
    }
}
int main(){
    read(n, m);
    for(int i=1;i<=m;i++){
        read(s[i][0]);
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=s[i][0];j++){
            read(s[i][j]);
            vis[s[i][j]]=true;
        }
        for(int j=s[i][1];j<=s[i][s[i][0]];j++){
            if(vis[j])
                continue;
            for(int k=1;k<=s[i][0];k++){
                if(!hasedge[j][s[i][k]]){
                    du[s[i][k]]++;
                    G[j].push_back(s[i][k]);
                    hasedge[j][s[i][k]] = true;
                }
            }
        }
    }
    bfs();
    printf("%d", ans);
}