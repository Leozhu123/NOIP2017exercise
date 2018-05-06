#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;
const int maxn=200005;
int val[maxn];
vector<int> G[maxn],RG[maxn],NG[maxn];
stack<int> S;
int tot=1;
bool vis1[maxn],vis2[maxn];
int com[maxn];
int sum[maxn];
int dp[maxn];
int from[maxn];
int to[maxn];
int n,m;
inline void addEdge(int from, int to)
{
    G[from].push_back(to);
	RG[to].push_back(from);
}
inline void addNEdge(int from, int to)
{
    NG[from].push_back(to);
}
void dfs1(int x)
{
	vis1[x]=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if(!vis1[v]){
			dfs1(v);
		}
	}
	S.push(x);
}	
void dfs2(int x){
	com[x]=tot;
	sum[tot]+=val[x];
	vis2[x]=true;
	for (int i=0;i<RG[x].size();i++){
		int v=RG[x][i];
		if(!vis2[v]){
			dfs2(v);
		}
	}
}
void search(int x){
    if(dp[x]) return;
    dp[x]=sum[x];
    int maxsum=0;
    for (int i=0;i<NG[x].size();i++){
        int v=NG[x][i];
        if(!dp[v]) search(v);
        maxsum=max(maxsum,dp[v]);
    }
    dp[x]+=maxsum;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    for (int i=0;i<m;i++){
        scanf("%d%d",&from[i],&to[i]);
        addEdge(from[i],to[i]);
    }
    for (int i=1;i<=n;i++){
        if(!vis1[i]){
            dfs1(i);
        }
    }
	while (!S.empty()){
		int a=S.top();
		S.pop();
		if(!vis2[a]){
			dfs2(a);
			tot++;
		}
	}
    for (int i=0;i<m;i++){
        if(com[from[i]]!=com[to[i]]){
            addNEdge(com[from[i]],com[to[i]]);
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        if(!dp[i]) search(i);
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}
