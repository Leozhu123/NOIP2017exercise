#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#define LL long long
using namespace std;
const LL maxn = 500005;
LL a[maxn];
LL ans = 0;
LL r[maxn];
void msort(int s, int t)
{
    if (s == t)
        return;
    int mid = (s + t) >> 1;
    msort(s, mid);
    msort(mid + 1, t);
    int i = s;
    int j = mid + 1;
    int k = s;
    while (i <= mid && j <= t)
    {
        if (a[i] <= a[j])
        {
            r[k] = a[i];
            k++;
            i++;
        }
        else
        {
            r[k] = a[j];
            k++;
            j++;
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        r[k] = a[i];
        k++, i++;
    }
    while (j <= t)
    {
        r[k] = a[j];
        k++, j++;
    }
    for (int i = s; i <= t; i++)
        a[i] = r[i];
}
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    msort(1, n);
    cout << ans;
}
