#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const long long maxn = 200000;
vector<long long> G[maxn];
vector<pair<long long, long long> > edges;
long long fa[maxn];
long long dp[maxn][3];
inline void addEdge(long long u, long long v, long long w)
{
    edges.push_back(pair<long long, long long>(v, w));
    edges.push_back(pair<long long, long long>(u, w));
    G[u].push_back(edges.size() - 2);
    G[v].push_back(edges.size() - 1);
}
long long dfs(long long x)
{
    dp[x][0] = dp[x][1] = dp[x][2] = 0;
    for (long long i = 0; i < G[x].size(); i++)
    {
        pair<long long, long long> e = edges[G[x][i]];
        if (e.first != fa[x])
        {
            fa[e.first] = x;
            long long t = e.second + dfs(e.first);
            if (t > dp[x][0])
            {
                dp[x][1] = dp[x][0];
                dp[x][0] = t;
            }
            else if (t > dp[x][1])
            {
                dp[x][1] = t;
            }
            dp[x][2] = max(max(dp[x][2],dp[e.first][2]), dp[x][0] + dp[x][1]);
        }
    }
    return dp[x][0];
}
long long dfs2(long long curr, long long del, long long x)
{
    long long t1 = dp[curr][0];
    long long t2 = dp[curr][1];
    long long t3 = dp[curr][2];
    dp[curr][0] = dp[curr][1] = dp[curr][2] = 0;
    for (long long i = 0; i < G[curr].size(); i++)
    {
        if (G[curr][i] == del || G[curr][i] == del + 1)
            continue;
        pair<long long, long long> e = edges[G[curr][i]];
        if (e.first != fa[curr])
        {
            long long t = e.second + dp[e.first][0];
            if (t > dp[curr][0])
            {
                dp[curr][1] = dp[curr][0];
                dp[curr][0] = t;
            }
            else if (t > dp[curr][1])
            {
                dp[curr][1] = t;
            }
            dp[curr][2] = max(max(dp[curr][2],dp[e.first][2]), dp[curr][0] + dp[curr][1]);
        }
    }
    if ((t1 == dp[curr][0] && t2 == dp[curr][1] && t3 == dp[curr][2]) || curr == 1)
    {
        return dp[1][2] + dp[x][2];
    }
    else
    {
        long long t = dfs2(fa[curr], del, x);
        dp[curr][0] = t1;
        dp[curr][1] = t2;
        dp[curr][2] = t3;
        return t;
    }
}
long long n;
long long ans = 0, ans_i = 0;
int main()
{
    cin >> n;
    for (long long i = 0; i < n - 1; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    fa[1] = 0;
    dfs(1);
    for (long long i = 0; i < n-1; i++)
    {
        long long d = i << 1;
        pair<long long, long long> e = edges[d], e2 = edges[d + 1];
        long long u = e.first, v = e2.first;
        long long curr, x;
        if (fa[u] == v)
        {
            curr = v;
            x = u;
        }
        else
        {
            curr = u;
            x = v;
        }
        long long t = dfs2(curr, d, x);
        if (t >= ans)
        {
            ans_i = i;
            ans = t;
        }
    }
    cout << ans << endl;
    //cout << ans_i << endl;
}