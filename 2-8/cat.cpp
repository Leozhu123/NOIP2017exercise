#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10;
int n, w, num[maxn], a[maxn], maxd, sumb[maxn];
bool ok, used[maxn];
bool cmp(int a, int b)
{
    if (a > b)
        return true;
    return false;
}
bool dfs(int x, int maxd, int rest)
{ //使用前x只猫，最多用maxd个缆车，总共还剩rest的空间
    bool ok = false;
    if (x == n + 1)
        return true;
    if (sumb[x] > rest)
        return false;
    for (int i = 0; i < maxd; i++)
    {
        if (w - a[i] >= num[x])
        {
            a[i] += num[x];
            ok = ok || dfs(x + 1, maxd, rest - num[i]);
            a[i] -= num[x];
        }
    }
    return ok;
}
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1, cmp);
    for (int i = n; i > 0; i--)
    {
        sumb[i] = sumb[i + 1] + num[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            a[j] = 0;
            used[j] = false;
        }
        maxd = i;
        if (dfs(1, maxd, w * maxd))
            break;
    }
    cout << maxd;
}