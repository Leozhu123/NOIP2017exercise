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
char ans[105][105];
char a[105];
int n, k;
LL quick_power(LL x, LL a, LL P)
{
    LL ans = 1;
    while (a)
    {
        if (a & 1)
        {
            ans *= x;
            ans %= P;
        }
        x = x * x;
        x %= P;
        a >>= 1;
    }
    return ans % P;
}
char f(int i, int k)
{
    if (k == 0)
    {
        return a[i];
    }
    //cout << i << " " << k << endl;
    if (ans[i][k] != '\0')
        return ans[i][k];
    char win1 = f(i, k - 1);
    char win2 = f((i - 1 + quick_power(2, k - 1, n)) % n + 1, k - 1);
    if (win1 == win2)
        return ans[i][k] = win1;
    if (win1 == 'R' && win2 == 'S')
        return ans[i][k] = 'R';
    if (win1 == 'S' && win2 == 'R')
        return ans[i][k] = 'R';
    if (win1 == 'P' && win2 == 'R')
        return ans[i][k] = 'P';
    if (win1 == 'R' && win2 == 'P')
        return ans[i][k] = 'P';
    if (win1 == 'S' && win2 == 'P')
        return ans[i][k] = 'S';
    if (win1 == 'P' && win2 == 'S')
        return ans[i][k] = 'S';
}
int main()
{
    read(n, k);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
//    cout << f(1, 1) << " " << f(3, 1) << endl;
    cout << f(1, k);
}