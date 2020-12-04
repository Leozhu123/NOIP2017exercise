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
int main()
{
    LL r1, c1, r2, c2;
    read(r1, c1, r2, c2);
    if (r1 == c1 && r2 == c2)
    {
        cout << 0;
        return 0;
    }
    if (abs(r1 - r2) + abs(c1 - c2) <= 3)
    {
        cout << 1;
        return 0;
    }
    if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2)
    {
        cout << 1;
        return 0;
    }
    if (abs((r1 + c1) - (r2 + c2)) <= 3 || abs((r1 - c1) - (r2 - c2)) <= 3)
    {
        cout << 2;
        return 0;
    }
    if (((r1 + c1 + r2 + c2) % 2 == 0))
    {
        cout << 2;
        return 0;
    }
    else
    {
        if (abs(r1 - r2) + abs(c1 - c2) <= 6)
        {
            cout << 2;
            return 0;
        }
        cout << 3;
        return 0;
    }
}