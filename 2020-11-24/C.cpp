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
int t;
const int maxn = 2e5 + 5;
int a[maxn];
int cnt[maxn];
bool has[maxn];
int main()
{
    read(t);
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(has, 0, sizeof(has));
        int n;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            has[a[i]] = true;
        }
        for (int i = 2; i <= n; i++)
        {
            if (a[i] != a[i - 1])
                cnt[a[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i != a[n] && has[i])
                cnt[i]++;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (has[i] && cnt[i] < ans)
                ans = cnt[i];
        }
        cout << (ans == INT_MAX ? 0 : ans) << endl;
    }
}