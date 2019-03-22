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
#define LL long long
#define P pair<int,int>
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
bool isv(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(){
    int x,y,z;
    int a,b,c;
    read(x, y, z, a, b, c);
    int sum = a + b + c;
    bool ok=true;
    if(a>=x)
        a -= x,sum-=x;
    else
        ok = false;
    if(a + b >= y)
        sum-=y;
    else ok=false;
    if(sum<z) ok=false;
    if(ok)puts("YES");
    else
        puts("NO");
}