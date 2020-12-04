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
double f[105][105][105];
bool vis[105][105][105];
double E(int a, int b, int c)
{
    double sum = a + b + c;
    if (vis[a][b][c])
        return f[a][b][c];
    if (a == 100 || b == 100 || c == 100)
    {
        return 0;
    }
    vis[a][b][c] = true;
    double ans = 1;
    if (a != 0)
    {
        ans += E(a + 1, b, c) * a / sum;
    }
    if (b != 0)
    {
        ans += E(a, b + 1, c) * b / sum;
    }
    if (c != 0)
    {
        ans += E(a, b, c + 1) * c / sum;
    }
    f[a][b][c] = ans;
    return ans;
}
int main(){
    int a,b,c;
    read(a,b,c);
    printf("%.9lf", E(a, b, c));
}