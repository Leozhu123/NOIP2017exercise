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
    int T = rand() % 20;
    cout << T << endl;
    while (T--)
    {
        int n = rand() % 500;
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << (LL)rand() * rand() % P  << " ";
        }
        cout << endl;
    }
}