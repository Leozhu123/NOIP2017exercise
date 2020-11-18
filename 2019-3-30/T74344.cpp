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
const int P = 19260817;

LL fast_pow(LL a, LL x, LL k)
{
    LL now = a;
    LL ans = 1;
    while (x)
    {
        if (x & 1)
            ans = (ans % k * now % k) % k;
        now = (now % k * now % k) % k;
        x >>= 1;
    }
    return ans;
}

int main()
{
    int t;
    read(t);
    while (t--)
    {
        LL n;
        read(n);
        cout << ((n - 2) * fast_pow(2, n - 1, P) + 1) % P << endl;
    }
}