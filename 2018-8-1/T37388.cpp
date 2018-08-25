#include <cstdio>
#include <iostream>
using namespace std;

int poww(int a, int b, int mod = 19260817)
{
    int ans = 1, base = a;
    while (b != 0)
    {
        if (b & 1 != 0)
            ans = (ans % mod * base % mod) % mod;
        base = (base % mod * base % mod) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int mod = 19260817;
    int m;
    cin >> m;
    while (m--)
    {
        int ans = 0;
        int n;
        cin >> n;
        ans = (ans % mod + poww(2, n) % mod) % mod;
        if ((n - 4) >= 0)
            ans -= 2 * poww(2, n - 4);
        for (int i = n - 5; i >= 0; i--)
        {
            ans = (ans % mod - (poww(2, i) * (i + 3)) % mod) % mod;
        }
        if (n>=3)ans -= 1;
        printf("%d\n", ans);
    }
}