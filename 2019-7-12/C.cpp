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
#define P pair<int, int>
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
LL a[maxn];
LL dp[maxn];
int main()
{
    LL n, m, k;
    read(n, m, k);
    for (LL i = 1; i <= m; i++)
    {
        read(a[i]);
        a[i]--;
    }
    LL ans = 1;
    dp[1] = a[1] / k;
    int len = 1;
    for (LL i = 2; i <= m; i++)
    {
        if((a[i] - (i - 1) + len) / k == dp[i-1]){
            dp[i] = dp[i-1];
            len++;
        }else{
            len = 1;
            ans++;
            dp[i] = (a[i] - (i - 1)) / k;
        }
    }
    cout << ans;
}