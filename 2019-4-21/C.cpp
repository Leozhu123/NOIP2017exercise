//by ciwomuli
//AK JSOI 2019
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
int t;
int main()
{
    read(t);
    while (t--)
    {
        int n;
        read(n);
        int l = 1, r = n;
        int mid = n / 2;
        int ans = 0;
        int lsans = 0;
        cout << mid << " " << n - mid << " ";
        for (int i = 1; i <= n;i++)
            cout << i << " ";
        cout << endl;
        cin >> lsans;
        ans = max(ans, lsans);
        for (int i = 1; i <= 8; i++)
        {
            int x = (l + mid) / 2;
            cout << x << " " << n - x << " ";
            for (int j = 1; j <= n;j++)
                cout << j << " ";
            cout << endl;
            int a;
            cin >> a;
            if (a > ans)
                mid = x,r = x;
            else
                l = x, mid = r;
            ans = max(a, ans);
        }
        cout << -1<<" "<<ans<<endl;
    }
}