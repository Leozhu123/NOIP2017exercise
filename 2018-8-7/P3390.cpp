#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int a[105][105];
int n, k;
int fast_mi(int a[105][105], int k)
{
    int ans[105][105];
    int now[105][105];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            now[i][j] = a[i][j];
    k--;
    while (k)
    {
        if (k & 1)
        {
            int ne[100][100];
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    ne[i][j] = 0;
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int k = 1; k <= n; k++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        ne[i][j] = ne[i][j] % mod + ans[i][k] * now[k][j];
                        ne[i][j] = ne[i][j] % mod;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    ans[i][j] = ne[i][j];
                }
            }
        }
        k >>= 1;
        int ne[100][100];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ne[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int j = 1; j <= n; j++)
                {
                    ne[i][j] = ne[i][j] % mod + now[i][k] * now[k][j];
                    ne[i][j] = ne[i][j] % mod;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                now[i][j] = ne[i][j];
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    int a[105][105];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    fast_mi(a,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j]<<" ";
        }
        cout << endl;
    }
}