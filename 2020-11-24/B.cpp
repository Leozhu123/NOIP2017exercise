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
int t;
const int maxn = 2e5 + 5;
int cnt[maxn], a[maxn];
int main(){
    read(t);
    while(t--){
        memset(cnt, 0, sizeof(cnt));
        int n;
        read(n);
        for (int i = 1; i <= n;i++){
            read(a[i]);
            cnt[a[i]]++;
        }
        int ans = -1;
        for (int i = 1; i <= n;i++){
            if(cnt[i] == 1){
                ans = i;
                break;
            }
        }
        if(ans == -1){
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= n;i++){
            if(a[i] == ans){
                cout << i << endl;
                break;
            }
        }
    }
}