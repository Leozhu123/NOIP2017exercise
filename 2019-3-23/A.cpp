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
int t, n, l, r, X, k;
int main(){
    read(t, n, l, r, X, k);
    int ans = 0;
    int speed = l;
    int dang = 1;
    int tm = 0;
    for (int i = 1; i <= t;i++){
        int x, y;
        read(x, y);
        if(x==0){
            dang++;
            speed = l;
            if(dang>n){
                ans = -1;
                break;
            }
        }else if(x==1){
            dang--;
            speed = r;
            if(dang == 0){
                ans = -1;
                break;
            }
        }
        if(y==1){
            speed = min(speed + X, r);
        }
        if(speed==r)
            tm++;
        else
            tm = 0;
        ans += dang * speed;
        if(tm==k)
            break;
    }
    cout << ans;
}