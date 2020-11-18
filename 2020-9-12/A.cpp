#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define LL long long
using namespace std;
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
int a[105];
bool v233[105];
int main()
{
    int T;
    read(T);
    while (T--)
    {
        int n;
        read(n);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        for (int i = 0; i <= n; i++)
        {
            int ma = 0, mb = 0;
            memset(v233, 0, sizeof(v233));
            for (int j = 1; j <= i; j++)
            {
                v233[a[j]] = true;
            }
            for (int j = 0; j <= 100; j++)
            {
                if (!v233[j])
                {
                    ma = j;
                    break;
                }
            }
            memset(v233, 0, sizeof(v233));
            for (int j = i + 1; j <= n; j++)
            {
                v233[a[j]] = true;
            }
            for (int j = 0; j <= 100; j++)
            {
                if (!v233[j])
                {
                    mb = j;
                    break;
                }
            }
            ans = max(ans, ma + mb);
        }
        cout << ans << endl;
    }
}