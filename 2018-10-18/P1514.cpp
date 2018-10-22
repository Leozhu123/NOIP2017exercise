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
using namespace std;
const int maxn = 510;
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
int l[maxn][maxn],r[maxn][maxn];
int high[maxn][maxn];
int n,m;
bool vis[maxn][maxn];
int xx[4] = {-1, 0, 1, 0};
int yy[4] = {0, 1, 0, -1};
void dfs(int x,int y){
    vis[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(nx<1 || nx>n || ny<1 || ny>m)
            continue;
        if(high[nx][ny]>=high[x][y])
            continue;
        if(!vis[nx][ny])
            dfs(nx, ny);
        l[x][y] = min(l[x][y], l[nx][ny]);
        r[x][y] = max(r[x][y], r[nx][ny]);
    }
}
int main(){
    read(n, m);
    memset(l, 0x3f, sizeof(l));
    for(int i=1;i<=m;i++)
        l[n][i] = r[n][i] = i;
    for(int i=1;i<=n;i++)
        for (int j = 1; j <= m;j++)
            read(high[i][j]);
    for(int i=1;i<=m;i++)
        if(!vis[1][i])
            dfs(1, i);
    bool flag = false;
    int cnt = 0;
    for(int i=1;i<=m;i++){
        if(!vis[n][i]){
            flag = true;
            cnt++;
        }
    }
    if(flag){
        puts("0");
        printf("%d",cnt);
        return 0;
    }
    int left=1;
    while(left<=m){
        int maxr = 0;
        for(int i=1;i<=m;i++){
            if(l[1][i]<=left){
                maxr = max(maxr, r[1][i]);
            }
        }
        cnt++;
        left = maxr + 1;
    }
    puts("1");
    printf("%d", cnt);
}