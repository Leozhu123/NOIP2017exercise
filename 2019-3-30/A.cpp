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
int main()
{
    int n;
    read(n);
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        read(x);
        if (x == 0)
            ans1 = max(ans1, i);
        else
            ans2 = max(ans2, i);
    }
    cout << min(ans1, ans2);
}