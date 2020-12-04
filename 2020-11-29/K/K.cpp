//by ciwomuli
//enter ICPC WF 2020
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
const int maxn = 100;
int a[maxn], b[maxn];
int main(){
    LL l,r;
    read(l, r);
    int pos1 = 0, pos2 = 0;
    while(l){
        a[pos1++] = l % 2;
        l /= 2;
    }
    while(r){
        b[pos2++] = r % 2;
        r /= 2;
    }
    LL ans = 0;
    for (int i = pos2 - 1; i >= 0;i--){
        if(a[i] == b[i]){
            if(b[i]){
                ans |= (LL)1 << i;
            }
        }else{
            ans += ((LL)1 << (i + 1)) - 1;
            break;
        }
    }
    cout << ans;
}