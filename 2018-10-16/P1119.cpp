#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 205;
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
int n,m,q;
int fix[maxn];
int dis[maxn][maxn][maxn];
int main(){
    read(n,m);
    for(int i=0;i<n;i++){
        read(fix[i]);
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i=1;i<=m;i++){
        int u,v,w;
        read(u, v, w);
        dis[0][u][v] = dis[0][v][u] = w;
    }
    for(int i=0;i<n;i++) dis[0][i][i]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dis[0][i][j] = min(dis[0][i][j], dis[0][i][0] + dis[0][0][j]);
    for (int k = 1; k < n;k++)
        for(int i=0;i<n;i++)
            for (int j = 0;j<n;j++)
                dis[k][i][j] = min(dis[k - 1][i][j], dis[k - 1][i][k] + dis[k - 1][k][j]);
    read(q);
    for(int i=1;i<=q;i++){
        int u,v,t;
        read(u, v, t);
        int _t = upper_bound(fix, fix + n, t) - fix - 1;
        printf("%d\n",(t<fix[u] || t<fix[v] || dis[_t][u][v]==0x3f3f3f3f)?-1:dis[_t][u][v]);
    }
}