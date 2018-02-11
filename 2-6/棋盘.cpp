#include <iostream>
#include <cstdio>
#include <queue>
struct pos
{
    int x, y;
    pos() : x(0), y(0) {}
    pos(int x, int y) : x(x), y(y) {}
};
using namespace std;
const int INF=(1<<31)-1,add_x[4] = {1, 0, -1, 0}, add_y[4] = {0, 1, 0, -1};
int n, m, board[105][105], nboard[105][105], cost[105][105];
bool vis[105][105];
queue<pos> q;
int main()
{
    cin >> n >> m;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            cost[i][j]=INF;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = nboard[a][b] = c + 1;
    }
    q.push(pos(1, 1));
    cost[1][1] = 0;
    while (!q.empty())
    {
        pos x = q.front();
        q.pop();
        cout<<x.x<<"  "<<x.y<<"  "<<cost[x.x][x.y]<<endl;
        vis[x.x][x.y]=false;
        for (int i = 0; i < 4; i++)
        {
            int nx = x.x + add_x[i], ny = x.y + add_y[i];
            if ( nx<1 || nx>n || ny<1 || ny>n) continue;
            if (nboard[nx][ny] == nboard[x.x][x.y] && cost[nx][ny] > cost[x.x][x.y])
            {
            	cout<<"case1 "<<nx<<"  "<<ny<<"  "<<cost[x.x][x.y]<<endl;
                cost[nx][ny] = cost[x.x][x.y];
                if (!vis[nx][ny]) q.push(pos(nx, ny));
                vis[nx][ny]=true;
            }
            else if (board[nx][ny] != 0 &&  (cost[nx][ny] > cost[x.x][x.y] + 1))
            {
            	cout<<"case2 "<<nx<<"  "<<ny<<"  "<<cost[x.x][x.y]+1<<endl;
                cost[nx][ny] = cost[x.x][x.y] + 1;
                if (!vis[nx][ny]) q.push(pos(nx, ny));
                vis[nx][ny]=true;
            } else if (board[x.x][x.y]!=0 && board[nx][ny]==0 && cost[nx][ny] > cost[x.x][x.y]+2){
            	cout<<"case3 "<<nx<<"  "<<ny<<"  "<<cost[x.x][x.y]+2<<endl;
                nboard[nx][ny]=board[x.x][x.y];
                cost[nx][ny]=cost[x.x][x.y]+2;
                if (!vis[nx][ny]) q.push(pos(nx,ny));
                vis[nx][ny]=true;
            }
        }
        if (board[x.x][x.y]==0) nboard[x.x][x.y]=0; else cout<<"fini "<<x.x<<"  "<<x.y<<"  "<<board[x.x][x.y]<<endl;
    }
    if (cost[n][n]==INF) cout<<-1;
    else cout<<cost[n][n];
}
