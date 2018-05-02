#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;
const long long maxn=400005;
long long val[maxn];
vector<long long> G[maxn],NG[maxn];
stack<long long> S;
long long tot;
bool visited[maxn];
bool instack[maxn];
long long com[maxn];
long long sum[maxn];
long long low[maxn];
long long dfn[maxn];
long long dp[maxn];
long long from[maxn];
long long to[maxn];
long long index;
long long n,m;
inline void addEdge(long long from, long long to)
{
    G[from].push_back(to);
}
inline void addNEdge(long long from, long long to)
{
    NG[from].push_back(to);
}
void tarjan(long long x){
	visited[x]=true;
    dfn[x]=low[x]=index++;
    S.push(x);
    instack[x]=true;
    for (long long i=0;i<G[x].size();i++){
        long long v=G[x][i];
        if(!visited[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if (instack[v]){
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x]){
    	tot++;
    	long long j;
        do{
            j=S.top();
            S.pop();
            instack[j]=false;
            com[j]=tot;
            sum[tot]+=val[j];
        }while (j!=x);
    }
}
void search(long long x){
    if(dp[x]) return;
    dp[x]=sum[x];
    long long maxsum=0;
    for (long long i=0;i<NG[x].size();i++){
        long long v=NG[x][i];
        if(!dp[v]) search(v);
        maxsum=max(maxsum,dp[v]);
    }
    dp[x]+=maxsum;
}
int main(){
    scanf("%ld%ld",&n,&m);
    for (long long i=1;i<=n;i++){
        scanf("%ld",&val[i]);
    }
    for (long long i=0;i<m;i++){
        scanf("%ld%ld",&from[i],&to[i]);
        addEdge(from[i],to[i]);
    }
    for (long long i=1;i<=n;i++){
        if(!visited[i]){
            tarjan(i);
        }
    }
    for (long long i=0;i<m;i++){
        if(com[from[i]]!=com[to[i]]){
            addNEdge(com[from[i]],com[to[i]]);
        }
    }
    long long ans=0;
    for (long long i=1;i<=n;i++){
        if(!dp[i]) search(i);
        ans=max(ans,dp[i]);
    }
    printf("%ld",ans);
    return 0;
}
