#include <iostream>
#include <queue>
#pragma GCC optimize(2)
#include <vector>
#define P pair<int, int>
struct State
{
    int a, b, x, y;
    State(int a, int b, int c, int d) : a(a), b(b), x(c), y(d) {}
};
using namespace std;
const int maxn = 4005;
queue<State> q;
bool map[maxn][maxn];
bool vis[maxn][maxn];
int n, m, r, c, x, y;
int ans = 0;
int main()
{
    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            map[i][j] = ch == '*' ? 1 : 0;
        }
    }
    q.push(State(r, c, x, y));
    while (!q.empty())
    {
        State s = q.front();
        q.pop();
        ans++;
       // cout << s.a << " " << s.b << endl;
        vis[s.a][s.b] = true;
        if (!vis[s.a][s.b + 1] && s.a >= 1 && s.a <= n && s.b + 1 >= 1 && s.b + 1 <= m && s.y >= 1 && !map[s.a][s.b + 1])
        {
            q.push(State(s.a, s.b + 1, s.x, s.y - 1));
            vis[s.a][s.b+1] = true;
        }
        if (!vis[s.a][s.b - 1] && s.a >= 1 && s.a <= n && s.b - 1 >= 1 && s.b - 1 <= m && s.x >= 1 && !map[s.a][s.b - 1])
        {
            q.push(State(s.a, s.b - 1, s.x - 1, s.y));
            vis[s.a][s.b-1] = true;
        }
        if (!vis[s.a + 1][s.b] && s.a + 1 >= 1 && s.a + 1 <= n && s.b >= 1 && s.b <= m && !map[s.a + 1][s.b])
        {
            q.push(State(s.a + 1, s.b, s.x, s.y));
            vis[s.a+1][s.b] = true;
        }
        if (!vis[s.a - 1][s.b] && s.a - 1 >= 1 && s.a - 1 <= n && s.b >= 1 && s.b <= m && !map[s.a - 1][s.b])
        {
            q.push(State(s.a - 1, s.b, s.x, s.y));
            vis[s.a-1][s.b] = true;
        }
    }
/*    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          //  cout << vis[i][j];
            if(vis[i][j])
                ;
     //       ans++;
        }
      //  cout << endl;
    }*/
    cout << ans;
}