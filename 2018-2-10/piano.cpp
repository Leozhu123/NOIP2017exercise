#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = (1 << 30) - 1;
int xx, l, tt, i, j, k1, l1, ans, t;
int p[19];
int f[1100][60][60];
bool pan(int x, int y)
{
    bool jl[70];
    memset(jl, 0, sizeof(jl));
    for (int i = max(0, x - 4); i <= x + 4; i++)
        jl[i] = true;
    for (int i = max(0, y - 4); i <= y + 4; i++)
        jl[i] = true;
    for (int i = 1; i <= xx; i++)
    {
        if (!jl[p[i]])
            return false;
    }
    return true;
}
int main()
{
    freopen("piano.in","r",stdin);
    freopen("piano.out","w",stdout);
    cin >> tt;
    for (int i = 0; i < 1100; i++)
        for (int j = 0; j < 60; j++)
            for (int k = 0; k < 60; k++)
                f[i][j][k] = INF;
    for (int i = 5; i <= 48; i++)
        for (int j = i + 1; j <= 48; j++)
            f[0][i][j] = 1;
    for (int l = 1; l <= tt; l++)
    {
        cin >> xx;
        for (int i = 1; i <= xx; i++)
            cin >> p[i];
        for (int i = 5; i <= 48; i++)
            for (int j = i + 1; j <= 48; j++)
                if (pan(i, j))
                    for (int k = 5; k <= 48; k++)
                        for (int m = 5; m <= 48; m++)
                            f[l][i][j] = min(f[l][i][j], f[l - 1][k][m] + (k - i) * (k - i) + (m - j) * (m - j));
    }
    ans = INF;
    for (int i = 5; i <= 48; i++)
        for (int j = 5; j <= 48; j++)
            ans = min(ans, f[tt][i][j]);
    cout << ans;
}