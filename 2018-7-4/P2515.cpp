#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const long long maxn = 405;
long long val[maxn],weight[maxn];
vector<long long> G[maxn], NG[maxn];
stack<long long> S;
long long tot;
bool visited[maxn];
bool instack[maxn];
long long com[maxn];
long long sumval[maxn],sumweight[maxn];
long long low[maxn];
long long dfn[maxn];
long long from[maxn];
long long to[maxn];
long long fa[maxn];
long long dp[maxn][maxn];
long long index;
long long n, m;
inline void addEdge(long long from, long long to)
{
    G[from].push_back(to);
}
inline void addNEdge(long long from, long long to)
{
    NG[from].push_back(to);
}
void tarjan(long long x)
{
    visited[x] = true;
    dfn[x] = low[x] = index++;
    S.push(x);
    instack[x] = true;
    for (long long i = 0; i < G[x].size(); i++)
    {
        long long v = G[x][i];
        if (!visited[v])
        {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if (instack[v])
        {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (low[x] == dfn[x])
    {
        tot++;
        long long j;
        do
        {
            j = S.top();
            S.pop();
            instack[j] = false;
            com[j] = tot;
            sumval[tot] += val[j];
            sumweight[tot] += weight[j];
        } while (j != x);
    }
}
void dfs(long long now){
    dp[now][sumweight[now]] = sumval[now];
    if(NG[now].size()==1){
        for (long long i = sumweight[now];i <= m;i++) dp[now][i] = dp[now][sumweight[now]];
        return;
    }
    for(long long i=0;i<NG[now].size();i++){
        long long x = NG[now][i];
        if(fa[now]!=x){
            fa[x]=now;
            dfs(x);
            for (long long j = m;j > 1;j--)
                for (long long k = 0;k <= j;k++){
          	        if (j-k > 0) dp[now][j] = max(dp[now][j],dp[x][k] + dp[now][j-k]);
            }
        }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &weight[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &val[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &from[i]);
        to[i] = i;
        addEdge(from[i], to[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            tarjan(i);
        }
    }
    for (long long i = 0; i < m; i++)
    {
        if (com[from[i]] != com[to[i]])
        {
            addNEdge(com[from[i]], com[to[i]]);
        }
    }
    dfs(0);
    printf("%lld", dp[0][m]);
    return 0;
}