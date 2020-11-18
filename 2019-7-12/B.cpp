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

int main(){
    string p[3];
    cin >> p[0] >> p[1] >> p[2];
    if(p[0][0] == p[1][0] && p[1][0] == p[2][0] && 
        p[0][1] == p[1][1] && p[1][1] == p[2][1]){
            cout << 0;
            return 0;
    }
    sort(p, p + 3);
    if(p[1][0] == p[0][0] + 1 && p[2][0] == p[1][0] + 1 &&
        p[0][1] == p[1][1] && p[1][1] == p[2][1]){
            cout<<0;
            return 0;
        }
    if(p[0][0] == p[1][0] && p[0][1] == p[1][1]){
        cout << 1;
        return 0;
    }
    if(p[1][0] == p[2][0] && p[1][1] == p[2][1]){
        cout << 1;
        return 0;
    }
    if(p[0][0] == p[2][0] && p[0][1] == p[2][1]){
        cout << 1;
        return 0;
    }
    if(p[0][0] + 1 == p[1][0] && p[0][1] == p[1][1]){
        cout << 1;
        return 0;
    }
    if(p[1][0] + 1 == p[2][0] && p[1][1] == p[2][1]){
        cout << 1;
        return 0;
    }
    if(p[0][0] + 1 == p[2][0] && p[0][1] == p[2][1]){
        cout << 1;
        return 0;
    }
    if(p[0][0] + 2 == p[1][0] && p[0][1] == p[1][1]){
        cout << 1;
        return 0;
    }
    if(p[1][0] + 2 == p[2][0] && p[1][1] == p[2][1]){
        cout << 1;
        return 0;
    }
    if(p[0][0] + 2 == p[2][0] && p[0][1] == p[2][1]){
        cout << 1;
        return 0;
    }
    cout << 2;
}