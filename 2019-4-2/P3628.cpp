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
const int maxn = 1e6 + 5;
LL n, a, b, c, s[maxn], dp[maxn];
int head, tail, q[maxn];
double S(double x)
{
    return x * x;
}
double slope(int x, int y)
{
    return 1. * (dp[x] + a * S(s[x]) - b * (s[x]) - (dp[y] + a * S(s[y]) - b * s[y])) / (s[x] - s[y]);
}
int main()
{
    read(n);
    read(a, b, c);
    for (int i = 1; i <= n; i++)
    {
        read(s[i]);
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        while (head < tail && slope(q[head + 1], q[head]) > 2 * a * s[i])
            head++;
        dp[i] = dp[q[head]] + a * S(s[i] - s[q[head]]) + b * (s[i] - s[q[head]]) + c;
        while(head < tail && slope(q[tail],q[tail-1]) < slope(i,q[tail]))
            tail--;
        q[++tail] = i;
    }
    cout << dp[n];
}