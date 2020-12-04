//by ciwomuli
//enter ICPC WF 2020
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
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
const LL P = 1e9 + 7;
int main()
{
    srand(time(NULL));
    int n = 100000;
    int m = rand() % n;
    cout << n << " " << m << endl;
    cout << 1 << " " << rand() * rand() << endl;
    for (int i = 2; i <= n; i++)
    {
        int u = rand() % 2 + 1;
        cout << u << " ";
        if (u == 1)
        {
            cout << rand() * rand();
        }
        cout << endl;
    }
}