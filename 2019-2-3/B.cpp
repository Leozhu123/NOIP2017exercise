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
#define LL long long
#define LD long double
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
const int maxn = 1e5 + 5;
int a[maxn];
int main(){
    int n,k,m;
    read(n,k,m);
    int mx = 0;
    for(int i=1;i<=n;i++){
        read(a[i]);
        mx = max(a[i], mx);
    }
    LD ans = 0;
    sort(a+1,a+n+1,greater<int>());
    LL sum = 0;
    for (int i = 1; i <= n;i++){
        sum+=a[i];
        int cnt = max(0, m - (n - i));
        if(cnt==0)
            continue;
        ans = max(ans, (LD)(sum + min(i * k, cnt)) / (LD)i);
    }
    cout << ans;
}