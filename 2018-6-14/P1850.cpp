#include <algorithm>
#include <iomanip>
#include <iostream>
const long long maxn = 2005;
const long long INF = (1 << 20) - 1;
using namespace std;
long long dis[maxn][maxn];
long double dp[maxn][maxn][2];
long long c[maxn], d[maxn];
long double k[maxn];
inline void init()
{
    for (long long i = 0; i <= maxn; i++)
        for (long long j = 0; j <= maxn; j++)
            dis[i][j] = dp[i][j][0] = dp[i][j][1] = INF;
}
int main()
{
    init();
    long long n, m, v, e;
    cin >> n >> m >> v >> e;
    for (long long i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (long long i = 1; i <= e; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = dis[a][b];
    }
    for (long long k = 1; k <= v; k++)
    {
        for (long long i = 1; i <= v; i++)
        {
            for (long long j = 1; j <= v; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    dp[1][1][1] = dp[1][0][0] = 0;
    for (long long i = 2; i <= n; i++)
    {
        for (long long j = 0; j <= m; j++)
        {
            dp[i][j][0] = min(dp[i - 1][j][0] + dis[c[i - 1]][c[i]],
                              dp[i - 1][j][1] + k[i - 1] * dis[d[i - 1]][c[i]] + (1 - k[i - 1]) * dis[c[i - 1]][c[i]]);
            if (j > 0)
                dp[i][j][1] = min(dp[i - 1][j - 1][0] + k[i] * dis[c[i - 1]][d[i]] + (1 - k[i]) * dis[c[i - 1]][c[i]],
                                  dp[i - 1][j - 1][1] + k[i] * (k[i - 1] * dis[d[i - 1]][d[i]] + (1 - k[i - 1]) * dis[c[i - 1]][d[i]]) + (1 - k[i]) * (k[i - 1] * dis[d[i - 1]][c[i]] + (1 - k[i - 1]) * dis[c[i - 1]][c[i]]));
        }
    }
    double ans = 2333333333;
    for (long long j = 0; j <= m; j++)
        ans = min({ans,
                   dp[n][j][0],
                   dp[n][j][1]});
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}