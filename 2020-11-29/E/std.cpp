//by ciwomuli
//both enter ICPC WF
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
int cnt = 1;
int n, m;
const int maxn = 1e5 + 5;
double ans[maxn];
int main(){
    read(n, m);
    int u;
    double v;
    read(u);
    scanf("%lf", &v);
    ans[cnt++] = v;
    for (int i = 2; i <= n;i++){
        read(u);
        if(u == 1){
            scanf("%lf", &v);
            ans[cnt++] = v;
        }else{
            double mx = -1e9;
            double mi = 1e9;
            for (int j = max(1, cnt - m); j <= cnt - 1;j++){
                mx = max(mx, ans[j]);
            }
            for (int j = max(1, cnt - m); j <= cnt - 1;j++){
                mi = min(mi, ans[j]);
            }
            v = (mx + mi) / 2;
            printf("%.1lf\n", v);
            ans[cnt++] = v;
        }
    }
}