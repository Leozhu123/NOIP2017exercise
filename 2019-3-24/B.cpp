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
#include <string>
#include <regex>
#include <sstream>
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
const LL P = 1e9 + 7;
int main(){
    int n;
    read(n);
    LL ans=1;
    for (int i = 1;i<=n;i++)
        ans *= 4,ans %= P;
//    ans -= (n-3) * 26;
    ans = (ans % P + P) % P;
//    if(n==3)
//        ans = 61;
    cout << ans;
}