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
const LL p = 998244353;
const LL g = 3, gi = 332748118;
const int maxn = 4e6 + 5;
LL A[maxn], B[maxn];
inline LL fastpow(LL x, LL k)
{
    LL ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return ans % p;
}
LL inv(LL x)
{
    return fastpow(x, p - 2);
}
void rader(LL F[], int n)
{
    int j = n >> 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (i < j)
            swap(F[i], F[j]);
        int k = n >> 1;
        while (j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if (j < k)
            j += k;
    }
}

void DFT(LL F[], int n, int c)
{
    rader(F, n);
    for (int k = 2; k <= n; k <<= 1)
    {
        LL wi = fastpow(c == 1 ? g : gi, (p - 1) / k);
        for (int j = 0; j < n; j += k)
        {
            LL w = 1;
            for (int i = j; i < j + k / 2; i++)
            {
                int u = F[i], v = w * F[i + k / 2] % p;
                F[i] = u + v >= p ? u + v - p : u + v;
                F[i + k / 2] = u - v < 0 ? u - v + p : u - v;
                w = w * wi % p;
            }
        }
    }
}
int main()
{
    int n, m, N = 1;
    LL k;
    read(n, k);
    for (int i = 0; i < n; i++)
        read(A[i]);
    B[0] = 1;
    for (int i = 1; i < n; i++)
    {
        B[i] = B[i - 1] * ((k + i - 1) % p) % p;
        B[i] = B[i] * inv(i) % p;
    }
    m = n = n - 1;
    while (N <= n + m)
        N <<= 1;
    DFT(A, N, 1);
    DFT(B, N, 1);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * B[i] % p;
    LL invt = fastpow(N, p - 2);
    DFT(A, N, -1);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * invt % p;
    for (int i = 0; i <= n; i++)
    {
        printf("%lld\n", A[i]);
    }
}
