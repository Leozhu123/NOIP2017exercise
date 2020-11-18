//by ciwomuli
//AK JSOI 2019
//I love wyt
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
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
const int maxn = 100005;
double p[maxn];
double x1[maxn], x2[maxn], ans[maxn];
int main(){
    int n;
    read(n);
    for (int i = 1;i<=n;i++)
        cin >> p[i];
    for (int i = 1;i<=n;i++){
        x1[i] = (x1[i-1] + 1) * p[i];
        x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p[i];
        ans[i] = ans[i - 1] + (3 * x2[i - 1] + 3 * x1[i - 1] + 1) * p[i];
    }
    printf("%.1lf",ans[n]);
}