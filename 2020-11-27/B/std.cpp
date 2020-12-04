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
    int f = 0, c = getchar();
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
const LL P = 1e9 + 7;
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
LL inv(LL a)
{
    return quick_power(a, P - 2, P) % P;
}
int a[505];
int main()
{
    int T;
    read(T);
    while (T--)
    {
        int n;
        LL ans = 0;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                LL sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += a[k];
                    sum %= P;
                }
                ans += sum * inv(j - i + 1) % P;
                ans %= P;
            }
        }
        ans = ans * inv(n * (n + 1) / 2) % P;
        cout << ans << endl;
    }
}