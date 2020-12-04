//by ciwomuli
//enter ICPC WF 2020
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
const int maxn = 1e5 + 5;
bool vis[maxn];
int cnt[maxn];
int ans[maxn];
LL tmp[maxn];
int t;
vector<int> prime;
int main()
{
    read(t);
    for (int i = 2; i <= maxn; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            for (int j = 2; i * j <= maxn; j++)
            {
                vis[i * j] = true;
            }
        }
    }
    while (t--)
    {
        LL n;
        read(n);
        memset(cnt, 0, sizeof(cnt));
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < prime.size(); i++)
        {
            tmp[i] = n;
            while (tmp[i] % prime[i] == 0)
            {
                tmp[i] /= prime[i];
                cnt[i]++;
            }
        }
        int max_ans = 0, x = 0;
        for (int i = 0; i < prime.size(); i++)
        {
            if (cnt[i] > max_ans)
            {
                max_ans = cnt[i];
                x = i;
            }
        }
        cout << (cnt[x] >= 1 ? cnt[x] : 1) << endl;
        for (int i = 1; i <= cnt[x] - 1; i++)
        {
            cout << prime[x] << " ";
        }
        if (cnt[x] >= 1)
            cout << tmp[x] * prime[x];
        else
            cout << n;
        cout << endl;
    }
}