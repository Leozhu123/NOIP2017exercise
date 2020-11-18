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

int main(){
    int T;
    read(T);
    for (int i = 1; i <= T;i++){
        int n;
        read(n);
        string str1, str2;
        cin >> str1 >> str2;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n;i++){
            if(str1[i]=='S')
                s1 += 2;
            else
                s1 -= str1[i] - 'A';
        }
        for (int i = 0; i < n;i++){
            if(str2[i]=='S')
                s2 += 2;
            else
                s2 -= str2[i] - 'A';
        }
        if(s1>s2) puts("A wins");
        else if(s1<s2) puts("B wins");
        else puts("Draw");
    }
}