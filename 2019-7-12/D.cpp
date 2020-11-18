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
int a[maxn];
int b[maxn];
int main()
{
    int n;
    read(n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        sum += a[i];
    }
    if (n >= 2)
    {
        if ((sum) % 2 == 1)
            puts("cslnb");
        else
            puts("sjfnb");
        return 0;
    }
    else
    {
        if ((sum) % 2 == 0)
            puts("cslnb");
        else
            puts("sjfnb");
        return 0;
    }
}