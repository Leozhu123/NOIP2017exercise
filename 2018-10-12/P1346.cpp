#include <iostream>
#include <climits>
#include <cctype>
#include <cstdio>
#include <algorithm>
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
const int maxn = 105;
int dis[maxn][maxn];
int n, a, b;
int main(){
    read(n,a,b);
    for(int i=1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            dis[i][j] = (1 << 20);
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        read(k);
        if(k==0)
            continue;
        int x;
        read(x);
        dis[i][x]=0;
        for (int j = 2;j<=k;j++){
            read(x);
            dis[i][x] = 1;
        }
    }
    for (int t = 1; t <= n;t++){
        for (int i = 1; i <= n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
            }
        }
    }
    if(dis[a][b]==(1<<20))
        puts("-1"); 
    else
        printf("%d", dis[a][b]);
}