//by ciwomuli
//AK JSOI 2019
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
const int maxn=1005;
int a[maxn][maxn];
int min1[maxn][maxn];
int max1[maxn][maxn];

inline int maxx(int a,int b){
    return a > b ? a : b;
}
inline int minn(int a,int b){
    return a < b ? a : b;
}

int main(){
    int n,m,k;
    read(n,m,k);
    for (int i = 1;i<=n;i++){
        for (int j = 1; j <= m;j++){
            read(a[i][j]);
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1; j <= m - k;j++){
            min1[i][j]=a[i][j];
            for (int ii = 0; ii < k;ii++){
                min1[i][j] = minn(min1[i][j], a[i][j + ii]);
            }
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1; j <= m - k;j++){
            max1[i][j]=a[i][j];
            for (int ii = 0; ii < k;ii++){
                max1[i][j] = maxx(max1[i][j], a[i][j + ii]);
            }
        }
    }
    int ans=INT_MAX;
    for (int j = 1; j <= m - k;j++){
        for (int i = 1; i <= n - k;i++){
            int mx = 0, mn = INT_MAX;
            for (int ii = 0; ii < k;ii++){
                mx = maxx(mx, max1[i + ii][j]);
                mn = minn(mn, min1[i + ii][j]);
            }
            ans = minn(mx - mn, ans);
        }
    }
    cout << ans;
}