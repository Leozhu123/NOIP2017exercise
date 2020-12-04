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
const int maxn = 1e5 + 5;
int fa[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find_root(int x)
{
    if (x == fa[x])
        return x;
    fa[x] = find_root(fa[x]);
    return fa[x];
}

void merge(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    fa[a] = b;
}

bool query(int a, int b)
{
    return find_root(a) == find_root(b);
}