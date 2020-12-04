//by ciwomuli
//enter ICPC WF 2020
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define LL long long
using namespace std;
template <typename T>
inline void read(T &t)
{
    LL f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
LL quick_power(LL x, LL a, LL P)
{
    LL ans = 1;
    while (a)
    {
        if (a & 1)
        {
            ans *= x;
            ans %= P;
        }
        x = x * x;
        x %= P;
        a >>= 1;
    }
    return ans % P;
}
const LL P = 1e9 + 7;
const LL maxn = 2e5 + 5;
LL a[maxn];
LL presum[maxn];
LL inv(LL a)
{
    return quick_power(a, P - 2, P) % P;
}
int main()
{
    LL T;
    read(T);
    while (T--)
    {
        LL n;
        read(n);
        memset(a, 0, sizeof(a));
        memset(presum, 0, sizeof(presum));
        for (LL i = 1; i <= n; i++)
        {
            read(a[i]);
            presum[i] = (i == 1) ? a[i] : presum[i - 1] + a[i];
            presum[i] %= P;
        }
        LL tmp = presum[n];
        LL ans = 0;
        for (LL i = 1; i <= n / 2; i++)
        {
            ans += tmp  % P * inv(i) % P;
            ans %= P;
            tmp += presum[n - i] - presum[i];
            tmp = (tmp + P) % P;
        }
        tmp = presum[n];
        for (LL i = n; i > n / 2; i--)
        {
            ans += tmp * inv(i) % P;
            ans %= P;
            tmp += presum[i - 1] - presum[n - i + 1];
            tmp %= P;
            tmp = (tmp + P) % P;
        }
        ans = ans * inv(((LL)n * (n + 1) / 2) % P) % P;
        cout << ans << endl;
    }
}