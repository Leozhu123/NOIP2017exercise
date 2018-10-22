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
using namespace std;
const int maxn = 200005;
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
int last[maxn],sum[maxn],cnt[maxn];
int n,k,p,color,price,now,ans;
int main(){
    read(n,k,p);
    for(int i=1;i<=n;i++){
        read(color,price);
        if(price<=p){
            now = i;
        }
        if(now>=last[color])
            sum[color] = cnt[color];
        last[color] = i;
        ans += sum[color];
        cnt[color]++;
    }
    printf("%d", ans);
}