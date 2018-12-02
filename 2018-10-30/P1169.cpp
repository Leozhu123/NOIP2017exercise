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
#define P pair<int,int>
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
const int maxn=2005;
int res[maxn][maxn];
int lef[maxn][maxn],righ[maxn][maxn];
int up[maxn][maxn];
int n, m;
int main(){
    read(n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            read(res[i][j]);
            lef[i][j]=j;
            righ[i][j]=j;
            up[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(res[i][j]!=res[i][j-1]){
                lef[i][j] = lef[i][j - 1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>0;j--){
            if(res[i][j]!=res[i][j+1]){
                righ[i][j] = righ[i][j + 1];
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1 && res[i][j]!=res[i-1][j]){
                lef[i][j]=max(lef[i][j],lef[i-1][j]);
                righ[i][j]=min(righ[i][j],righ[i-1][j]);
                up[i][j] = up[i - 1][j] + 1;
            }
            int a = righ[i][j] - lef[i][j] + 1;
            int b=min(a,up[i][j]);
            ans1=max(ans1,b*b);
            ans2 = max(ans2, a * up[i][j]);
        }
    }
    printf("%d\n%d", ans1, ans2);
}