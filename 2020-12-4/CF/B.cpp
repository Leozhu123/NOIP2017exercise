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
const LL maxn = 2e5 + 5;
LL a[maxn];
LL T;
int main()
{
    read(T);
    while (T--)
    {
        LL n;
        read(n);
        for (LL i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        LL sum = 0;
        for (LL i = n; i >= 2; i--)
        {
            sum += abs(a[i] - a[i - 1]);
        }
        LL ans = ((LL)1 << 62);
        for (LL i = 2; i <= n - 1; i++)
        {
            ans = min(ans, sum - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]));
        }
        ans = min(ans, sum - abs(a[2] - a[1]));
        ans = min(ans, sum - abs(a[n] - a[n - 1]));
        cout << ans << endl;
    }
}