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
int T, n;
const int maxn = 100005;
int a[maxn], b[maxn];
int main(){
    read(T);
    while(T--){
        read(n);
        for (int i = 1; i <= n;i++)
            read(a[i]);
        for (int i = 1; i <= n;i++)
            read(b[i]);
        int t = 0;
        bool ok = true;
        bool used = false;
        for (int i = 1; i <= n;i++){
            if(a[i] != b[i]){
                if(used)
                    ok = false;
                if(t == 0){
                    t = a[i] - b[i];
                    if(t > 0)
                        ok = false;
                }else{
                    if(a[i] - b[i] !=t){
                        ok = false;
                    }
                }
            }else if(t != 0){
                used = true;
            }
        }
        if(ok)
            puts("YES");
            else
                puts("NO");
    }
}