#include <bits/stdc++.h>
using namespace std;
bool ef(long long a, int n, long long s);
int a[100005];
int main()
{
    int n;
    long long s, l = 0, r = 100000005, mid, out;
    scanf("%d%lld", &n, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if (!ef(1, n, s))
    {
        cout << 0;
        return 0;
    }
    while (3 < r - l)
    {
        mid = (l + r) / 2;
        if (ef(mid, n, s))
            l = mid;
        else
            r = mid;
    }
    for (long long i = l; i <= r; i++)
    {
        if (ef(i, n, s))
            out = i;
    }
    printf("%lld", out);
    return 0;
}
bool ef(long long x, int n, long long s)
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] / x;
    }
    if (ans >= s)
        return 1;
    return 0;
}