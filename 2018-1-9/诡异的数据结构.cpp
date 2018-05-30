#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std; 
const int maxn=100005,INF=(1<<31)-1;
bool vis[maxn];
int p[maxn],n,dp[maxn],num[maxn];
vector<int> G[maxn],sons[maxn],gsons[maxn];
void BFS(int root){
  queue<int> q;
  q.push(root);
  p[root]=0;
  vis[root]=true;
  while (!q.empty()){
      int x=q.front();
      q.pop();
      if (p[x]!=0) sons[p[x]].push_back(x);
      if (p[p[x]]!=0) gsons[p[p[x]]].push_back(x);
      for (int i=0;i<G[x].size();i++){
        if (!vis[G[x][i]]){
          p[G[x][i]]=x;
          q.push(G[x][i]);
          vis[G[x][i]]=true;
      }
    }
  }
}  
int dps(int x){
  if (dp[x]) return dp[x];
  dp[x]=-INF;
  int ans=0;
  for (int i=0;i<sons[x].size();i++)
    ans+=dps(sons[x][i]);
  dp[x]=ans;
  ans=0;
  for (int i=0;i<gsons[x].size();i++)
    ans+=dps(gsons[x][i]);
  ans+=num[x];
  dp[x]=max(dp[x],ans);
  return dp[x];
}  
int main(){
  scanf("%d",&n);
  for (int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }  
  for (int i=1;i<=n;i++) scanf("%d",&num[i]);
  BFS(1);
  cout<<dps(1);
}  
