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
int game[maxn];
bool vis[maxn];
int ans;
int find_fa(int x)
{
    return fa[x] == x ? x : fa[x] = find_fa(fa[x]);
}
int main()
{
    int n, m, k;
    read(n, m, k);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        read(u, v);
        if (!game[v])
            game[v] = u;
        else
        {
            int a = find_fa(u), b = find_fa(game[v]);
            fa[a] = b;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[find_fa(i)])
        {
            vis[find_fa(i)] = true;
            ans++;
        }
    }
    if(k == 0)
        cout << n;
    else cout << ans - 1;
}
