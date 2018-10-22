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
const int maxn = 510;
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
int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int T;
    read(T);
    while(T--){
        int a0,a1,b0,b1;
        read(a0, a1, b0, b1);
        int p = a0 / a1;
        int q = b1 / b0;
        int ans=0;
        for (int x = 1; x*x <= b1;x++){
            if(b1%x==0){
                if(x%a1==0&&gcd(x/a1,p)==1&&gcd(q,b1/x)==1) ans++;
                int y=b1/x;
                if(x==y) continue; 
                if(y%a1==0&&gcd(y/a1,p)==1&&gcd(q,b1/y)==1) ans++;
            }
        }
        printf("%d\n", ans);
    }
}