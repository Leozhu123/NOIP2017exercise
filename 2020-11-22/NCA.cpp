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
LL a[maxn], b[maxn], score[maxn];
int n, m, p;
int main()
{
    read(n, m, p);
    for (int i = 1; i <= n; i++)
    {
        read(a[i], b[i]);
        score[i] = a[i] * 85 + b[i] * 15;
    }
    sort(score + 1, score + n + 1);
    LL my_score = score[n + 1 - m];
    LL ans = 0;
    if ((my_score - 15 * p) % 85 == 0)
    {
        ans = (my_score - 15 * p) / 85;
    }
    else
    {
        ans = (my_score - 15 * p) / 85 + 1;
    }
    ans = max(ans, (LL)0);
    cout << ans;
}