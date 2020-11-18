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
const int maxn = 2e5 + 5;
int p[maxn], t[maxn], l[maxn], r[maxn], d[maxn], u[maxn];
int head[maxn], nxt[maxn];
int tot = 0;
void ae(int p_, int t_, int l_, int r_, int d_, int u_)
{
    nxt[++tot] = head[p_];
    head[p_] = tot;
    t[tot] = t_;
    l[tot] = l_;
    r[tot] = r_;
    d[tot] = d_;
    u[tot] = u_;
}
struct CmpType
{
    bool operator(const pair<int, int> &l, const pair<int, int> &r)
    {
        return l.second > r.second;
    }
};
set<pair<int, int>> st[maxn << 2];
priority_queue<pair<int, int>, vector<pair<int, int>>, CmpType> pq;
void insert(int o,int lb,int rb,)
int main()
{
}