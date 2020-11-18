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
const int maxn = 2e5 + 5;
int n, a[maxn], m, cnt=1;
int main(){
    read(n,m);
    for (int i = 1; i <= n;i++){
        read(a[i]);
    }
    sort(a + 1, a + n + 1);
    LL ans = 0;
    int e = 0;
    for (int i = 1; i <= n;i++){
        e++;
        if(e > m ){
            e = 0;
            cnt++;
        }
        ans += a[i] * cnt;
        cout << ans << " ";
    }
}