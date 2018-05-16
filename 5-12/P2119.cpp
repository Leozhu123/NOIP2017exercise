#include <iostream>
using namespace std;
const int maxn = 40010;
int v[maxn], num[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i];
        num[v[i]]++;
    }
    for (int t = 1; t * 9 < n; t++)
    {
        int sum = 0;
        int va = 0, vb = 0, vc = 0, vd = 0;
        for (vd = t * 9 + 2; vd <= n; vd++)
        {
            va = vd - 9 * t - 1;
            vb = vd - 7 * t - 1;
            vc = vd - t;
            sum += num[vb] * num[va];
            c[vc] += num[vd] * sum;
            d[vd] += num[vc] * sum;
        }
        sum = 0;
        for (va = n - t * 9 - 1; va >= 1; va--)
        {
            vb = va + 2 * t;
            vc = va + t * 8 + 1;
            vd = va + t * 9 + 1;
            sum += num[vc] * num[vd];
            a[va] += num[vb] * sum;
            b[vb] += num[va] * sum;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << a[v[i]] << " " << b[v[i]] << " " << c[v[i]] << " " << d[v[i]] << endl;
    }
}