#include <iostream>
#include <climits>
#include <algorithm>
#define LL long long
const int maxn = 4000;
LL a[maxn], b[maxn];
LL suma[maxn], sumb[maxn];
LL mina[maxn], minb[maxn];
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];
        mina[i] = INT_MAX;
    }
    for (int i = 1; i <= m;i++){
        cin >> b[i];
        sumb[i] = sumb[i - 1] + b[i];
        minb[i] = INT_MAX;
    }
    LL x;
    cin >> x;
    for (int k = 1; k <= n;k++){
        for (int j = 1; j <= n - k + 1;j++){
            mina[k] = min(mina[k], suma[j + k - 1] - suma[j - 1]);
        }
    }
    for (int k = 1; k <= m;k++){
        for (int j = 1; j <= m - k + 1;j++){
            minb[k] = min(minb[k], sumb[j + k - 1] - sumb[j - 1]);
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mina[i] * minb[j] <= x)
                ans = max(ans, (LL)i * j);
        }
        }
    cout << ans;
}