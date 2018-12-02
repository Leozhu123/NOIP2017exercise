#include <iostream>
#include <cctype>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;
    int f=0,ch=getchar();
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    if(f) x=-x;
}
const int maxn=5005;
vector<int> G[maxn];
bool vis[maxn];
int tmp[maxn];
int ans[maxn];
int n,m;
int u[maxn],v[maxn];
int pos=1;
void dfs1(int x,int f){
    tmp[pos]=x;
    pos++;
    sort(G[x].begin(),G[x].end());
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(v!=f){
            dfs1(v,x);
        }
    }
}
void dfs2(int x,int f){
    tmp[pos]=x;
    pos++;
    vis[x]=true;
    sort(G[x].begin(),G[x].end());
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(v!=f && !vis[v]){
            dfs2(v,x);
        }
    }
    vis[x]=false;
}
int main(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        read(u[i]);read(v[i]);
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    for(int i=1;i<=n;i++) ans[i]=INT_MAX;
    if(m==n-1) {
        dfs1(1,0);
        for(int i=1;i<=n;i++) ans[i]=tmp[i];
    }else{
        for(int i=1;i<=m;i++){
            for(int k=1;k<=n;k++) G[k].clear();
            int cnt=0;
            for(int j=1;j<=m;j++){
                if(i==j) continue;
                G[u[j]].push_back(v[j]);
                G[v[j]].push_back(u[j]);
            }
            pos=1;
            dfs2(1,0);
            bool less=false;
            for(int i=1;i<=n;i++){
                if(tmp[i]<ans[i]) {less=true;break;}
                if(tmp[i]>ans[i]) {less=false;break;}
            }
            if(less && pos>n)
                for(int i=1;i<=n;i++)
                    ans[i]=tmp[i];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    puts("");
}
