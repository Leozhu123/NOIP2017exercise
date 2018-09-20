#include <iostream>
using namespace std;
const int maxn = 1e5;
int a[maxn], dp[maxn][2][2];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 3)
            dp[i][1][1] += dp[i - 1][1][1];
        else if (a[i] == 2)
        {
            dp[i][1][1] += dp[i - 1][0][1];
            dp[i][1][0] += dp[i - 1][1][1];
            dp[i][0][1] += dp[i - 1][1][0];
        }
        else if (a[i] == 1)
        {
            dp[i][1][0] += dp[i - 1][0][1];
            dp[i][0][1] += dp[i - 1][0][0];
            dp[i][0][0] += dp[i - 1][1][0];
        }
        else
            dp[i][0][0] += dp[i - 1][0][0];
    }
    cout << dp[n][0][0] + dp[n][1][0];
}