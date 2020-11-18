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
struct date{
    LL t,l,h;
};
bool cmpp(date d1,date d2){
    return d1.t < d2.t ? 1 : 0;
}
const int maxn = 105;
const LL  maxx = 1e9 + 7;
int T, n, m;
date d[maxn];
int main(){
    read(T);
    while(T--){
        read(n, m);
        for (int i = 1;i<=n;i++){
            read(d[i].t, d[i].l, d[i].h);
        }
        sort(d + 1, d + n + 1, cmpp);
        LL nh = min((LL)maxx,(LL)m + d[1].t);
        LL nl = max((LL)-maxx, (LL)m - d[1].t);
        bool ok = true;
        if(nl > d[1].h || nh < d[1].l)
            ok = false;
        else{
            nl = max(nl,d[1].l);
            nh = min(nh, d[1].h);
        }
        for (int i = 2;i<=n;i++){
            nh = min((LL)maxx,(LL)nh + d[i].t - d[i-1].t);
            nl = max((LL)-maxx, (LL)nl - d[i].t + d[i-1].t);
            if(nl > d[i].h || nh < d[i].l)
                ok = false;
            else{
                nl = max(nl,d[i].l);
                nh = min(nh, d[i].h);
            }
        }
        if(ok)
            cout << "YES"<<endl;
        else
            cout << "NO" << endl;
    }
}