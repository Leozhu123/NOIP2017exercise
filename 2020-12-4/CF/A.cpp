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
#include <set>
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
int T;
int main(){
    read(T);
    while(T--){
        set<int> s;
        int ans = 0;
        int n,m;
        read(n, m);
        for (int i = 1; i <= n;i++){
            int a;
            read(a);
            s.insert(a);
        }
        for (int i = 1;i<=m;i++){
            int a;
            read(a);
            if(s.count(a))
                ans++;
        }
        cout << ans << endl;
    }
}