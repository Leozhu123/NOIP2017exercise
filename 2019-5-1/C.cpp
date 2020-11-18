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
#include <stack>
#include <vector>
#include <string>
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
int n,z;
const int maxn = 1e5 + 5;
int a[maxn];
int dp[maxn][2];
int main(){
    read(n,z);
    for (int i = 1; i <= n;i++){
        read(a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n;i++){
        if(a[i] - a[i-1] <= z){
            dp[i][1] = dp[i - 1][0] + 1;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max(dp[n][0], dp[n][1]);
}