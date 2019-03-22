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
    LL f = 0, c = getchar();
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
const LL maxn = 1e5 + 5;
LL A,B,C,n,m;
LL t[maxn], b[maxn];
LL mxt = 0;
LL calc(LL x){
    LL ans = 0;
    for (LL i = 1;i<=n;i++){
        if(x > t[i])
            if(C==1e16)
                return LLONG_MAX;
            else ans += (x - t[i]) * C;
    }
    LL rest = 0, need = 0;
    for (LL i = 1;i<=m;i++)
        if(b[i] <= x) 
            rest += x - b[i];
        else
            need += b[i] - x;
    if(A<B){
        if(need <= rest)
            ans += A * need;
        else
            ans += A * rest + B * (need - rest);
    }else{
        ans += B * need;
    }
    return ans;
}
int main(){
    read(A, B, C);
    read(n, m);
    for (LL i = 1; i <= n;i++)
        read(t[i]),mxt = max(mxt,t[i]);
    for (LL i = 1; i <= m;i++)
        read(b[i]);
    LL l = 0, r = mxt;
    while(l + 8 < r){
        LL mid1 = l + (r - l) / 3;
        LL mid2 = l + (r - l) / 3 * 2;
        LL c1 = calc(mid1), c2 = calc(mid2);
        if(c1<=c2)
            r = mid2;
        else
            l = mid1;
    }
    LL res = LLONG_MAX;
    for (LL i = l; i <= r;i++){
        LL ans = calc(i);
        if(ans<res)
            res = ans;
    }
    cout << res;
}