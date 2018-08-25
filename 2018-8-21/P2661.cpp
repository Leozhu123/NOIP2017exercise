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
int main(){
    scanf("%lld",&n);
    for (long long i=1;i<=n;i++){
        scanf("%lld",&to[i]);
        from[i] = i;
        val[i] = 1;
        addEdge(from[i],to[i]);
    }
    for (long long i=1;i<=n;i++){
        if(!visited[i]){
            tarjan(i);
        }
    }
    ans = 1000000;
    for (int i = 0; i < tot;i++){
        if(sum[i]>1)
            ans = min(ans, sum[i]);
    }
        printf("%lld", ans);
    return 0;
}