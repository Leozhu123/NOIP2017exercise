//by ciwomuli
//AK JSOI 2019
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

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}
LL lcm(LL a, LL b)
{
    return a / gcd(a,b) * b;
}

LL x = LLONG_MAX, y = 0;
void upd(LL t)
{
    x = min(x, t);
    y = max(y, t);
}
int main()
{
    LL n, k, a, b;
    read(n, k, a, b);
    for (LL i = 0; i <= n; i++)
    {
        LL l = a + k * i + b;
        l = abs(l);
        if (l > 0)
        {
            LL t = lcm(n * k, l);
            upd(t / l);
        }
    }
    for (LL i = 0; i <= n; i++)
    {
        LL l = -a + k * i + b;
        l = abs(l);
        if (l > 0)
        {
            LL t = lcm(n * k, l);
            upd(t / l);
        }
    }
    for (LL i = 0; i <= n; i++)
    {
        LL l = a + k * i - b;
        l = abs(l);
        if (l > 0)
        {
            LL t = lcm(n * k, l);
            upd(t / l);
        }
    }
    for (LL i = 0; i <= n; i++)
    {
        LL l = -a + k * i - b;
        l = abs(l);
        if (l > 0)
        {
            LL t = lcm(n * k, l);
            upd(t / l);
        }
    }
    cout << x << " " << y;
}