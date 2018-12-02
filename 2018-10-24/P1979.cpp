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
#define LL long long
#define P pair<int, int>
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
const int maxn = 32;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, q;
int predis[maxn][maxn];
int dis[maxn * maxn * 5];
int vis[maxn * maxn * 5];
int a[maxn][maxn];
struct Edge
{
    int from, to, weight;
    Edge(int u, int v, int w) : from(u), to(v), weight(w) {}
};
struct Point
{
    int x, y;
    Point(int x,int y):x(x),y(y){}
};
vector<Edge> G[maxn * maxn * 5];
void ae(int u, int v, int w)
{
    G[u].push_back(Edge(u, v, w));
    //cout << u << " " << v << ' ' << w << endl;
    //G[v].push_back(Edge(v, u, w));
}
int num(int x, int y)
{
    y--;
    return (x - 1) * m + y << 2;
}
void bfs(int ex, int ey, int px, int py, int d)
{
    memset(predis, -1, sizeof(predis));
    predis[px][py] = 1;
    predis[ex][ey] = 0;
    queue<Point> q;
    q.push(Point(ex, ey));
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        int cx = cur.x, cy = cur.y;
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (a[nx][ny] && predis[nx][ny] == -1)
            {
                predis[nx][ny] = predis[cx][cy] + 1;
                q.push(Point(nx, ny));
            }
        }
    }
    //for (int i = 1; i <= n; i++)
    //{
    //    for (int j = 1; j <= m; j++)
    //    {
    //        printf("%3d", predis[i][j]);
    //    }
    //    cout<<endl;
    //}
    if (d == 233)
        return;
    int tmp = num(px, py);
    for (int i = 0; i < 4; i++)
    {
        int nx = px + dx[i];
        int ny = py + dy[i];
        if (predis[nx][ny] > 0)
        {
            ae(tmp + d, tmp + i, predis[nx][ny]);
        }
    }
    ae(tmp + d, num(ex, ey) + (d + 2) % 4, 1);
}
void spfa(int sx, int sy)
{
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    for (int i = 0; i < 4; i++)
    {
        int nx = sx + dx[i], ny = sy + dy[i];
        if (predis[nx][ny] != -1)
        {
            int tmp = num(sx, sy) + i;
            dis[tmp] = predis[nx][ny];
            q.push(tmp);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge &e = G[u][i];
            if (dis[e.to] == -1 || dis[e.to] > dis[u] + e.weight)
            {
                dis[e.to] = dis[u] + e.weight;
                if (!vis[e.to])
                {
                    vis[e.to] = true;
                    q.push(e.to);
                }
            }
        }
    }
}
int main()
{
    read(n, m, q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            read(a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
            {
                if (a[i - 1][j])
                    bfs(i - 1, j, i, j, 0);
                if (a[i][j + 1])
                    bfs(i, j + 1, i, j, 1);
                if (a[i + 1][j])
                    bfs(i + 1, j, i, j, 2);
                if (a[i][j - 1])
                    bfs(i, j - 1, i, j, 3);
            }
        }
    }
    int ex,ey,sx,sy,tx,ty,ans;
    while(q--){
        read(ex, ey, sx, sy, tx, ty);
        if(sx==tx && sy==ty){
            puts("0");
            continue;
        }
        bfs(ex, ey, sx, sy, 233);
        spfa(sx,sy);
        ans = INT_MAX;
        int tmp = num(tx, ty);
        for(int i=0;i<4;i++){
            if(dis[tmp+i]!=-1){
                ans = min(ans, dis[tmp + i]);
            }
        }
        if(ans==INT_MAX)
            puts("-1");
        else 
            printf("%d\n", ans);
    }
}