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
const int maxn = 4005;
int ll[maxn], rr[maxn];
int a[maxn];
int cnt = 1;
int main()
{
    int n, m;
    read(n, m);
    for (int i = 1; i <= m; i++)
    {
        int o, l, r;
        read(o, l, r);
        if (o == 1)
            for (int i = l + 1; i <= r; i++)
                a[i] = 1;
        else
            ll[cnt] = l, rr[cnt] = r, cnt++;
    }
    for (int i = 1; i <= cnt - 1; i++)
    {
        bool f = false;
        for (int j = ll[i] + 1; j <= rr[i]; j++)
        {
            if (a[j] != 1)
            {
                f = true;
                a[j] = 2;
            }
        }
        if (!f)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    int l = 1001;
    cout << 1 << " ";
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 2)
            cout << --l << " ";
        else
            cout << ++l << " ";
    }
}