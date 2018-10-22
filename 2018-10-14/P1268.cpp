#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#define LL long long
#define P pair<int,int>
using namespace std;
const int maxn = 1005;
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
int d[maxn][maxn];
int n;
int main(){
    while(1){
        read(n);
        if(n==0) break;
        for(int i=1;i<n;i++){
            for (int j = i+1; j <= n;j++){
                read(d[i][j]);
            }
        }
        int ans = d[1][2];
        for(int i=3;i<=n;i++){
            int t = INT_MAX;
            for(int j=2;j<i;j++){
                t = min(t, d[1][i] - (d[1][j] + d[1][i] - d[j][i]) / 2);
            }
            ans += t;
        }
        printf("%d\n", ans);
    }
}
