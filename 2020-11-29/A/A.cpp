#include <cctype>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <iostream>

template <typename T> inline void read(T& t) {
    long long f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
#if __cplusplus >= 201103L
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
    read(t); read(args...);
}
#else
template <typename T1, typename T2>
inline void read(T1& t1, T2& t2) { read(t1); read(t2); }
template <typename T1, typename T2, typename T3>
inline void read(T1& t1, T2& t2, T3& t3) { read(t1, t2); read(t3); }
template <typename T1, typename T2, typename T3, typename T4>
inline void read(T1& t1, T2& t2, T3& t3, T4& t4) { read(t1, t2, t3); read(t4); }
template <typename T1, typename T2, typename T3, typename T4, typename T5>
inline void read(T1& t1, T2& t2, T3& t3, T4& t4, T5& t5) { read(t1, t2, t3, t4); read(t5); }
#endif	// C++11

#ifdef WIN32
#define LLIO "%I64d"
#else
#define LLIO "%lld"
#endif	// WIN32 long long
#define rep(I, A, B) for (long long I = (A); I <= (B); ++I)
#define rrep(I, A, B) for (long long I = (A); I >= (B); --I)
#define erep(I, X) for (long long I = head[X]; I; I = next[I])

const long long maxn = 2e5 + 207;
long long sum[maxn << 5], left[maxn << 5], right[maxn << 5], root[maxn];
long long n, m, tot;

void insert(long long &curr, long long l, long long r, long long pos, long long val) {
    left[++tot] = left[curr]; right[tot] = right[curr];
    sum[tot] = sum[curr] + val; curr = tot;
    if (l == r) return;
    long long mid = (l + r) >> 1;
    if (pos <= mid) insert(left[curr], l, mid, pos, val);
    else insert(right[curr], mid + 1, r, pos, val);
}
long long queryKth(long long lt, long long rt, long long l, long long r, long long k) {
    if (l == r) return l;
    long long mid = (l + r) >> 1;
    long long s = sum[left[rt]] - sum[left[lt]];
    if (k <= s) return queryKth(left[lt], left[rt], l, mid, k);
    else return queryKth(right[lt], right[rt], mid + 1, r, k - s);
}
bool semi(long long a, long long b, long long c)
{
    if (a + b > c && c + b > a && a + c > b)
        return 1;
    return 0;
}
int main()
{
    read(n);
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        read(x);
        root[i] = root[i - 1];
        insert(root[i], -1e9, 1e9, x,1);
    }
    read(m);
    for (long long i = 1; i <= m; i++)
    {
        long long l, r;
        read(l, r);
        long long k = 1;
        bool found = false;
        while (k + 2 <= r - l + 1)
        {
            long long a = queryKth(root[l - 1], root[r], -1e9, 1e9, r - l + 2 - k);
            long long b = queryKth(root[l - 1], root[r], -1e9, 1e9, r - l + 2 - k - 1);
            long long c = queryKth(root[l - 1], root[r], -1e9, 1e9, r - l + 2 - k - 2);
//            std::cout << a << " " << b << " " << c << std::endl;
            long long ans = a + b + c;
            if (semi(a, b, c))
            {
                std::cout << ans << std::endl;
                found = true;
                break;
            }
            k++;
        }
        if (!found)
        {
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}
