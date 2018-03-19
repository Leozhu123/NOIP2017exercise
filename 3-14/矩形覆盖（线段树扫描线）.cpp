#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LL long long
#define INF 0x7fffffff
using namespace std;

const int maxn = 20005;

struct Seg
{
    double l, r, h;
    int c;
    Seg() {}
    Seg(double _l, double _r, double _h, double _c) : l(_l), r(_r), h(_h), c(_c) {}
    bool operator<(const Seg &a) const
    {
        return h < a.h;
    }
} S[maxn << 2];
double X[maxn << 2];

int cover[maxn << 2];  //统计区间的下边比上边多几条边
double sum[maxn << 2]; //用于统计长度

int b_search(double key, int n, double X[])
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (X[mid] == key)
            return mid;
        if (X[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

void getup(int rt, int l, int r)
{
    if (cover[rt])
        sum[rt] = X[r] - X[l];
    else if (l == r)
        sum[rt] = 0;
    else
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int rt, int l, int r, int L, int R, int c)
{
    if (L <= l && r <= R)
    {
        cover[rt] += c;
        getup(rt, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (mid > L)
        update(rt << 1, l, mid, L, R, c);
    if (mid < R)
        update(rt << 1 | 1, mid, r, L, R, c);
    getup(rt, l, r);
}

int main()
{
    int n, cas = 1;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        double a, b, c, d;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
            X[m] = a;
            S[m++] = Seg(a, c, b, 1);
            X[m] = c;
            S[m++] = Seg(a, c, d, -1);
        }
        sort(S, S + m);
        sort(X, X + m);
        int k = 1;
        for (int i = 1; i < m; i++)
        {
            if (X[i] != X[i - 1])
                X[k++] = X[i];
        }
        memset(cover, 0, sizeof(cover));
        memset(sum, 0, sizeof(sum));
        double ans = 0;
        for (int i = 0; i < m - 1; i++)
        {
            int l = b_search(S[i].l, k, X);
            int r = b_search(S[i].r, k, X);
            update(1, 0, k - 1, l, r, S[i].c);
            ans += sum[1] * (S[i + 1].h - S[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", cas++, ans);
    }
    return 0;
}