#include  <iostream >
#include <cstdio>
using namespace std;
int n, m, p, q, map[4005][4005], ans[4005][4005];
int main()
{
    cin >> n >> m;
    cin >> p >> q;
    for (int i = 0; i < p; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        for (int k = b; k <= y; k++)
        {
            ++map[a][k];
            --map[x + 1][k];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans[i][j] = ans[i - 1][j] + map[i][j];
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
}