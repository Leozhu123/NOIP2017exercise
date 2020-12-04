//by ciwomuli
//both enter ICPC WF
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
LL my_check(LL i, LL x)
{
    return i * (i + 1) / 2 <= x;
}
LL find_k(LL x)
{
    LL l = 1, r = (LL)sqrt(2 * x) + 10000000;
    while (r - l > 5)
    {
        LL mid = (l + r) / 2;
        //cout << mid * (mid + 1) / 2 << endl;
        if (!my_check(mid, x))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    for (int i = r; i >= l; i--)
    {
        if (my_check(i, x))
            return i;
    }
}
int main()
{
    LL x;
    read(x);
   // cout << find_k(x + 1) << endl;
    cout << x + 1 - find_k(x + 1);
}