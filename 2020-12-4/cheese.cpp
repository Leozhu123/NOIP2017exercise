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
const int maxn = 1005;
LL x[maxn], y[maxn], z[maxn];
vector<int> bot, top;
int fa[maxn];
int n, h;
LL r;
bool check(LL x1, LL y1, LL z1, LL x2, LL y2, LL z2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= 4 * r * r;
}
int find_fa(int x)
{
    return fa[x] == x ? x : fa[x] = find_fa(fa[x]);
}
void merge(int x, int y)
{
    x = find_fa(x);
    y = find_fa(y);
    fa[x] = y;
}
int main()
{
    int T;
    read(T);
    while (T--)
    {
        bot.clear();
        top.clear();
        read(n, h, r);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            read(x[i], y[i], z[i]);
            if (z[i] <= r)
                bot.push_back(i);
            if (z[i] >= h - r)
                top.push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (check(x[i], y[i], z[i], x[j], y[j], z[j]))
                {
                    merge(i, j);
                }
            }
        }
        bool ans = 0;
        for (int i = 0; i < bot.size();i++){
            for (int j = 0; j < top.size();j++){
                if(find_fa(bot[i])==find_fa(top[j])){
                    ans = 1;
                }
            }
        }
        if(ans){
            puts("Yes");
        }else{
            puts("No");
        }
    }
}