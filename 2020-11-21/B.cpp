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
const int maxn = 2e5 + 5;
string s;
char sta[maxn];
int pos = 0;
int main()
{
    int n;
    int i = 0;
    read(n);
    int ans = n;
    cin >> s;
    while (i < n)
    {
        if (s[i] == 'f')
        {
            sta[pos++] = 'f';
            i++;
        }
        else if (s[i] == 'o')
        {
            sta[pos++] = 'o';
            i++;
        }
        else if (s[i] == 'x')
        {
            if(sta[pos-2] == 'f' && sta[pos-1] == 'o'){
                ans -= 3;
                pos -= 2;
            }else{
                pos = 0;
            }
            i++;
        }
        else
        {
            pos = 0;
            i++;
        }
    }
    cout << ans;
}