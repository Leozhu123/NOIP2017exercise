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
#define LL long long
#define P pair<int,int>
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
const int maxn=3e5+5;
int a[maxn];
int main(){
    int n;
    read(n);
    for(int i=1;i<=n;i++)
        read(a[i]);
    LL ans=0;
    sort(a + 1, a + n + 1);
    for (int i = 1;i<=n/2;i++)
        ans += (a[i] + a[n-i+1]) * (a[i] + a[n-i+1]);
    cout << ans;
}