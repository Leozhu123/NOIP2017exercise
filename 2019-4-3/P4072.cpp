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

const int maxn = 1e5 + 5;
LL s[maxn], dp[maxn];
int q[maxn], cnt[maxn];
int n, m;
double y(int i)
{
    return dp[i] + s[i] * s[i];
}
double x(int i)
{
    return s[i];
}
double k(int i)
{
    return 2.0 * s[i];
}
double slope(int i, int j)
{
    return (y(i) - y(j)) / (x(i) - x(j));
}
bool check(LL mid)
{
    int head = 0, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head < tail && slope(q[head], q[head + 1]) < k(i))
            head++;
        int j = q[head];
        dp[i] = dp[j] + (s[i] - s[j]) * (s[i] - s[j]) + mid;
        cnt[i] = cnt[j] + 1;
        while (head < tail && slope(q[tail - 1], q[tail]) > slope(q[tail], i))
            tail--;
        q[++tail] = i;
    }
    return cnt[n] > m;
}
int main()
{
    read(n, m);
    for (int i = 1; i <= n; i++)
    {
        read(s[i]);
        s[i] += s[i - 1];
    }
    LL l = 0, r = LLONG_MAX, ans = 0;
    while (l <= r)
    {
        LL mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            ans = mid, r = mid - 1;
    }
    check(ans);
    cout << m * (dp[n] - ans * m) - s[n] * s[n];
}