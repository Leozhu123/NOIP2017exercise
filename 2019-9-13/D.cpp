//by ciwomuli
//AK JSOI 2019
//I love wyt
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
const int maxn = 2e5 + 5;
int a[maxn];
int ans[maxn];
int cnt[10];
int main()
{
    read(t);
    while (t--)
    {
        int n;
        read(n);
        bool ok1 = false;
        string str;
        cin >> str;
        for (int d = 0; d <= 9; d++)
        {
            bool ok = true;
            int max1 = 0, max2 = 0;
            for (int i = 0; i < 10; i++)
                cnt[i] = 0;
            for (int i = 1; i <= n; i++)
            {
                a[i] = str[i - 1] - '0';
                cnt[a[i]]++;
            }
            for (int i = 1; i <= n; i++)
            {
                if (a[i] < d)
                {
                    ans[i] = 1;
                    if (a[i] < max1)
                    {
                        ok = false;
                        break;
                    }
                    else
                        max1 = a[i];
                    cnt[a[i]]--;
                }
                else if (a[i] > d)
                {
                    ans[i] = 2;
                    if (a[i] < max2)
                    {
                        ok = false;
                        break;
                    }
                    else
                        max2 = a[i];
                    cnt[a[i]]--;
                }
                else
                {
                    int s = 0;
                    for (int i = 0; i < d; i++)
                        s += cnt[i];
                    if(s != 0){
                        ans[i] = 2;
                        if (a[i] < max2)
                        {
                            ok = false;
                            break;
                        }
                        else
                            max2 = a[i];
                    }else{
                        ans[i] = 1;
                        if (a[i] < max1)
                        {
                            ok = false;
                            break;
                        }
                        else
                            max1 = a[i];
                    }
                }
            }
            if (ok)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << ans[i];
                }
                cout << endl;
                ok1 = true;
                break;
            }
        }
        if (!ok1)
            cout << '-' << endl;
    }
}