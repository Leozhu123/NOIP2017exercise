#include <cctype>
#include <climits>
#include <cstdio>
#include <iostream>
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
const int maxn = 65;
int dis[maxn][maxn];
int n, m;
bool G[maxn][maxn][65];
int main()
{
    read(n, m);
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            dis[i][j] = (1<<20);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        read(x, y);
        dis[x][y] = 1;
        G[x][y][0] = true;
    }
    for (int k = 1; k <= 64; k++){
        for (int i = 1; i <= n;i++){
            for (int t = 1; t <= n;t++){
                for (int j = 1; j <= n;j++){
                    if(G[i][t][k-1]&&G[t][j][k-1]){
                        G[i][j][k]=1;
                        dis[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout << dis[1][n];
}