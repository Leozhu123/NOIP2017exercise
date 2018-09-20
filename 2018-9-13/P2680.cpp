#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define P pair<int,int>
const int maxn=300005;
const int inf=(1<<31)-1;
using namespace std;

struct Edge{
    int u,v,c;
    Edge(int u,int v,int c):u(u),v(v),c(c){}
};

vector<Edge> G[maxn];
vector<int> sons[maxn];
vector<P > plan;
int len[maxn];
int lca[maxn];
int fa[maxn][27];
int s[maxn];
int dep[maxn];
int cost[maxn];
int dis[maxn];
int cha[maxn];
int n,m;
void build_tree(int x,int f){
    fa[x][0]=f;
    for (int i=1;i<=25;i++){
        if (fa[x][i-1])
            fa[x][i]=fa[fa[x][i-1]][i-1];
        else break;
    }
    for(int i=0;i<G[x].size();i++){
        Edge &e=G[x][i];      
		if(e.v==f) continue;
        cost[e.v]=e.c;
        dis[e.v]=dis[x]+e.c;
        dep[e.v]=dep[x]+1;
        sons[x].push_back(e.v);
        build_tree(e.v,x);
    }
}
void calc_lca(){
    for(int i=0;i<plan.size();i++){
        P now=plan[i];
        int a=now.first,b=now.second;
        if (dep[a]<dep[b]){
            int tmp=a;
            a=b;
            b=tmp;
        }
        int delta=dep[a]-dep[b];
        for (int i=0;i<=25;i++){
            if(delta&(1<<i))
                a=fa[a][i];
        }
        if(a==b){
            lca[i]=a;
            continue;
        }
        for (int i=25;i>=0;i--){
            if(fa[a][i]!=fa[b][i]){
                a=fa[a][i];
                b=fa[b][i];
            }
        }
        lca[i]=fa[a][0];
    }
    for(int i=0;i<plan.size();i++){
        P now=plan[i];
        int a=now.first,b=now.second;
        len[i]=(dis[a]+dis[b]-2*dis[lca[i]]);
    }
}
int ret=0,num=0;
void dfs(int u){
    for(int i=0;i<sons[u].size();i++){
        int v=sons[u][i];
        dfs(v);
        cha[u]+=cha[v];
    }
    if(cha[u]==num){
        ret=max(ret,cost[u]);
    }
}
bool check(int mid){
    num=0;
    for(int i=0;i<=n;i++)
        cha[i]=0;
    int maxlen=0;
    for(int i=0;i<plan.size();i++){
        P now=plan[i];
        if(len[i]>mid) {
            num++;
            cha[now.first]++;
            cha[now.second]++;
            cha[lca[i]]-=2;
        }
        maxlen=max(maxlen,len[i]);
       // cout<<endl;
    }
    ret=0;
    dfs(1);
    //for(int i=1;i<=n;i++) cout<<cha[i]<<' ';
   // cout<<ret<<endl;
	if(maxlen-ret>mid) 
        return false;
    else return true;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        G[u].push_back(Edge(u,v,c));
        G[v].push_back(Edge(v,u,c));
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        plan.push_back(P(u,v));
    }
    dep[1]=0;
    build_tree(1,0);
    calc_lca();
    int l=1,r=inf;
    while(l+5<r){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    for(int i=l;i<=r;i++){
        if(check(i)) {
            cout<<i;
            return 0;
        }
    }
}
