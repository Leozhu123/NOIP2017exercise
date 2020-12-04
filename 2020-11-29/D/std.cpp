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
bool vis[maxn];
int main(){
    read(n, m);
    for (int i = 1;i<=m;i++){
        int op, pos;
        read(op, pos);
        if(op == 1){
            vis[pos] = true;
        }else{
            int k = pos;
            while(vis[k] && k <= n)
                k++;
            if (k > n)
                cout << -1 << endl;
            else{
                cout << k << endl;
            }
        }
    }
}