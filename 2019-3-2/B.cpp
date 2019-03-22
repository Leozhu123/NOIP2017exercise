#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <regex>
#include <sstream>
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
const int maxn = 2005;
const LL P = 19260817;
int n;
LL C[maxn][maxn];
int main(){
    C[0][0] = 1;
    for(int i=1;i<=2000;i++){
        for (int j = 0;j<=i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j] %= P;
        }
    }

    for (int i = 1; i <= 2000; i++)
    {
        for (int j = 1; j <= 2000; j++)
        {
            C[i][j] = C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1] + C[i][j];
            C[i][j] = (C[i][j] % P + P) % P;
        }
    }
    read(n);
    for(int i=1;i<=n;i++){
        int a,b;
        read(a,b);
        cout << C[b][a] << endl;
    }
}