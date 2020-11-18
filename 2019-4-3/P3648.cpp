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
int v[maxn];
int n, m;
double slope(int i, int j)
{
    if (s[i] == s[j])
        return -1e18;
    return ((dp[i] - s[i]*s[i]) - (dp[j] - s[j] * s[j])) / (s[j] - s[i]);
}
bool check(LL mid)
{
    int head = 0, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head < tail && slope(q[head], q[head + 1]) <= s[i])
            head++;
        int j = q[head];
        dp[i] = dp[j] + s[j] * (s[i] - s[j]) - mid;
        v[i] = j;
        cnt[i] = cnt[j] + 1;
        while (head < tail && slope(q[tail - 1], q[tail]) >= slope(q[tail], i))
            tail--;
        q[++tail] = i;
    }
    return cnt[n] > m + 1;
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
    for (int i = 1; i <= 16;i++){
        check(i);
        cout << dp[n] + i * m<<" "<<cnt[n];
        cout << endl;
    }
    cout << endl;
    check(ans);
    cout << ans << endl;
    cout << cnt[n] << endl;
    cout << dp[n] + ans * m;
}