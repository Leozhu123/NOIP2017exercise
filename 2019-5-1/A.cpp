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
bool ok = true;
const int maxn = 105;
int a[maxn];
int main(){
    int n;
    read(n);
    int ans = 0;
    for (int i = 1;i <= n;i++){
        read(a[i]);
        if(a[i] == 1 && a[i-1] == 2)
            ans += 3;
        if(a[i] == 1 && a[i-1] == 3)
            ans += 4;
        if(a[i] == 2 && a[i-1] == 1)
            ans += 3;
        if(a[i] == 2 && a[i-1] == 3)
            ok = false;
        if(a[i] == 3 && a[i-1] == 1)
            ans += 4;
        if(a[i] == 3 && a[i-1] == 2)
            ok = false;
        if(a[i] == 2 && a[i-1] == 1 && a[i - 2] == 3)
            ans--;
    }
    if(!ok) puts("Infinite");
    else {
        puts("Finite");
        cout << ans;
    }
}