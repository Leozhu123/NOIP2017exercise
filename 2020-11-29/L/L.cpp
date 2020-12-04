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
int n;
int a[15];
bool ac[20];
int main()
{
    read(n);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        ac[str[i] - 'A' + 1] = true;
    }
    int max_my = 0;
    int ans = 0;
    for (int i = 1; i <= 13; i++)
    {
        read(a[i]);
        if (a[i] > max_my && !ac[i])
        {
            max_my = a[i];
            ans = i;
        }
    }
    cout << (char)('A' + ans - 1);
}