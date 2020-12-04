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
const int maxn = 50;
int dp[maxn][maxn];
int n, t, a[maxn];
int main(){
    read(n, t);
    for (int i = 1; i <= n;i++){
        read(a[i]);
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1;j <)
            if (i - a[i] < 0)
                continue;
        
    }
}