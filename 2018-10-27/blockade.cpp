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
const int maxn = 50005;
const int log_n = 25;
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
    int from,to,weight;
    Edge(int f,int t,int w):from(f),to(t),weight(w){}
};
vector<Edge> G[maxn];
int army[maxn];
int fa[maxn][log_n];
LL dis[maxn][log_n];
bool vis[maxn];
bool used[maxn];
int restbj[maxn];
LL restmin[maxn];
int n,m;
int l=0, r;
int LOG=0;
inline void dfs1(int x,int f,int d){
    fa[x][0]=f;
    dis[x][0]=d;
    for(int i=1;i<=LOG;i++){
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        dis[x][i] = dis[fa[x][i - 1]][i-1] + dis[x][i - 1];
    }
    for(int i=0;i<G[x].size();i++){
        Edge &e=G[x][i];
        if(e.to==f)
            continue;
        dfs1(e.to, x, e.weight);
    }
    return;
}
vector<P > rests;
vector<P > resta;
inline bool dfs2(int x,int f){
    bool flag=true;
    if(vis[x])
        return true;
    if(G[x].size()==1)
        flag = false;
    for(int i=0;i<G[x].size();i++){
        Edge &e=G[x][i];
        if(e.to==f)
            continue;
        flag=dfs2(e.to,x) && flag;
        if(f!=0 && !flag)
            break;
    }
    if(!flag){
        if(f==1){
            rests.push_back(P(dis[x][0], x));
        }
        return false;
    }
    return true;
}
inline bool check(int mid){
    memset(vis,0,sizeof(vis));
    memset(used,0,sizeof(used));
    memset(restbj,0,sizeof(restbj));
    memset(restmin, 0, sizeof(restmin));
    rests.clear();
    resta.clear();
    for(int i=1;i<=m;i++){
        int x=army[i];
        int num=0;
        for (int j = LOG;j>=0;j--){
            if(fa[x][j]>1 && num+dis[x][j]<=mid){
                num += dis[x][j];
                x = fa[x][j];
            }
        }
        if(fa[x][0]==1 && num+dis[x][0]<=mid){
            resta.push_back(P(mid - num - dis[x][0], i));
            if(!restbj[x] || mid - num - dis[x][0]<restmin[x]){
                restmin[x] = mid - num - dis[x][0];
                restbj[x] = i;
            }
        }else{
            vis[x] = true;
        }
    }
    if(dfs2(1,0))
        return true;
    sort(rests.begin(), rests.end(), greater<P>());
    sort(resta.begin(), resta.end(), greater<P>());
    if(rests.size()>resta.size())
        return 0;
    int now = 0;
    used[0] = 1;
    for(int i=0;i<rests.size();i++){
        if(!used[restbj[rests[i].second]]){
            used[restbj[rests[i].second]]=true;
            continue;
        }
        while(now<resta.size() && (used[resta[now].second] || resta[now].first<rests[i].first))
            now++;
        if(now>=resta.size())
            return 0;
        used[resta[now].second] = true;
    }
    return 1;
}
int main(){
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    read(n);
    while((1<<LOG)<n) LOG++;
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        read(u,v,w);
        r += w;
        G[u].push_back(Edge(u, v, w));
        G[v].push_back(Edge(v, u, w));
    }
    read(m);
    for(int i=1;i<=m;i++){
        read(army[i]);
    }
    dfs1(1,0,0);
    if(!check(r)){
        puts("-1");
        return 0;
    }
    while(l+3<r){
        int mid = (l + r) >> 1;
        if(check(mid)) 
            r = mid;
        else
            l = mid;
    }
    for (int i = l; i <= r;i++){
        if(check(i)){
            printf("%d",i);
            return 0;
        }
    }
}
