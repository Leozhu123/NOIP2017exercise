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
int fa[maxn], ch[maxn][2], rev[maxn], x[maxn], da[maxn];
void upd(int o)
{
    x[o] = da[o] ^ x[ch[o][0]] ^ x[ch[o][1]];
}
void pud(int o)
{
    if (rev[o])
    {
        swap(ch[o][0], ch[o][1]);
        rev[ch[o][0]] ^= 1;
        rev[ch[o][1]] ^= 1;
        rev[o] = 0;
    }
}
int idon(int o)
{
    if (o == ch[fa[o]][0])
        return 0;
    if (o == ch[fa[o]][1])
        return 1;
    return -1;
}
void rot(int x)
{
    int y = fa[x], d = idon(x);
    if (idon(y) != -1)
        ch[fa[y]][idon[y]] = x;
    fa[x] = fa[y];
    ch[y][d] = ch[x][d ^ 1];
    fa[ch[y][d]] = y;
    ch[x][d ^ 1] = y;
    fa[y] = x;
    upd(y);
    upd(x);
}
void mt(int o)
{
    if (!idon(o) == -1)
        mt(fa[o]);
    pud(o);
}
void splay(int x)
{
    mt(x);
    while (idon(x) != -1)
        rot(x);
}
void access(int x)
{
    for (int y = 0; x; y = x, x = fa[x])
    {
        splay(x);
        ch[x][1] = y;
        upd(x);
    }
}
void mkrt(int x)
{
    access(x);
    splay(x);
    rev[x] ^= 1;
    pud(x);
}
int frt(int x){
    access(x);
    splay(x);
    while(ch[x][0])
        x = ch[x][0];
    return x;
}
int main()
{
}