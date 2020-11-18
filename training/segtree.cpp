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
int lch[maxn], rch[maxn], x[maxn], delta[maxn], a[maxn], tot;
void uod(int o)
{
    x[o] = x[lch[o]] + x[rch[o]];
}
void pud(int o, int l, int r)
{
    int mid = (l + r) >> 1;
    if (delta[o])
    {
        x[lch[o]] += (mid - l + 1) * delta[o];
        x[rch[o]] += (r - mid) * delta[o];
        delta[lch[o]] += delta[o];
        delta[rch[o]] += delta[o];
        delta[o] = 0;
    }
}
void build(int &o, int l, int r)
{
    o = ++tot;
    if (l == r)
    {
        x[tot] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lch[o], l, mid);
    build(rch[o], mid + 1, r);
    upd(o);
}
void modify(int o, int l, int r, int L, int R, int a)
{
    if (L <= l && r <= R)
    {
        delta[o] += a;
        x[o] += (r - l + 1) * a;
        return;
    }
    int mid = (l + r) >> 1;
    pud(o, l, r);
    if (L <= mid)
        modify(lch[o], l, mid, L, R, a);
    if (R >= mid + 1)
        modify(rch[o], mid + 1, r, L, R, a);
    upd(o);
}
int query(int o,int l,int r,int L,int R){
    if(L <=l && r <= R){
        return x[o];
    }
    int mid=(l+r)>>1;
    upd(o, l, r);
    int ans = 0;
    if(L <= mid)
        ans += query(lch[o], l, mid, L, R);
    if (R >= mid + 1)
        ans += query(rch[o], mid + 1, r, L, R);
    return ans;
}
int main()
{
}