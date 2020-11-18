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
const int maxn = 2e5 + 5;
char s[maxn];
int val[256][maxn];
int cnt[256];
int main()
{
    int n;
    read(n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        val[s[i]][++cnt[s[i]]] = i;
    read(n);
    for (int i = 1; i <= n; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", s + 1);
        int l = strlen(s + 1);
        int ans = 0;
        for (int j = 1; j <= l; j++)
            ans = max(ans, val[s[j]][++cnt[s[j]]]);
        cout << ans << endl;
    }
}