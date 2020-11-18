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
#include <stack>
#include <vector>
#include <string>
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
int n;
char str[105];
int main(){
    read(n);
    if(n % 2 == 1){
        puts("No");
        return 0;
    }
    scanf("%s",str);
    bool a = true;
    for (int i = 0; i < n / 2;i++){
        if(str[i] != str[n/2 + i])
            a = false;
    }
    if(a)
        puts("Yes");
        else
            puts("No");
}