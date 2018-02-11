#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std; 
const int maxn=10005,INF=(1<<31)-1;
bool G[maxn][maxn],vis[maxn];
int p[maxn],n,dp[maxn];
vector<int> sons[maxn],gsons[maxn];
ofstream ou("a.out");
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
    for (int i=1;i<=n;i++){
      if (G[x][i] && !vis[i]){
        p[i]=x;
        q.push(i);
        vis[i]=true;
      }
    }
  }
}  
int dps(int x){
  if (dp[x]) return dp[x];
  int ans=0;
  for (int i=0;i<sons[x].size();i++)
    ans+=dps(sons[x][i]);
  dp[x]=ans;
  ans=0;
  for (int i=0;i<gsons[x].size();i++)
    ans+=dps(gsons[x][i]);
  ans++;
  dp[x]=max(dp[x],ans); ou<<x<<": "; 
  for (int i=1;i<=n;i++) ou<<dp[i]<<' ';
  cout<<endl;
  return dp[x];
}  
int main(){
  scanf("%d",&n);
  for (int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    G[u][v]=1;
    G[v][u]=1;
  }  
  BFS(1);
  ou<<dps(1);
}  
