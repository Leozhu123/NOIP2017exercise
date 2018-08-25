#include <cstdio>
#include <iostream>

using namespace std;

const long long maxn = 1000005;
const long long M = 998244353;

long long tri[2005][2005];
long long a[maxn];
long long sum[maxn];

void init()
{
    tri[1][1] = 1;
    for (long long i = 2; i <= 2001; i++)
    {
        for (long long j = 1; j <= i; j++)
        {
            tri[i][j] = (tri[i - 1][j - 1] % M + tri[i - 1][j] % M) % M;
        }
    }
}
int main()
{
    long long n, q;
    cin >> n;
    init();
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for (long long i = 1; i <= q; i++)
    {
        long long x, y;
        cin >> x >> y;
        long long now = y;
        long long ans = 0;
        for (long long j = 1; j <= x+1; j++)
        {
            ans = (ans % M + tri[x+1][j] % M * a[now] % M)%M;
           // ans += tri[x+1][j] * a[now];
         //   cout << ans << " "<<now<<" "<<a[now]<<endl;
            now = now % n + 1;
        }
        cout << ans << endl;
    }
}