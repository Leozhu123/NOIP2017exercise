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
const int maxn = 300003;
int q, n, a[maxn], o[maxn];
int main()
{
    read(q);
    while (q--)
    {
        read(n);
        for (int i = 1; i <= n; i++)
            read(a[i]);
        for (int i = 1; i <= n; i++)
            read(o[i]);
        o[n + 1] = -20020404;
        int z = 1;
        for (int i = 1; i <= n; i++)
        {
            if (o[i] > o[i + 1])
                sort(a + z, a + i + 1), z = i + 1;
        }
        bool g = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != o[i])
            {
                g = false;
                puts("NO");
                break;
            }
        }
        if (g)
            puts("YES");
    }
}