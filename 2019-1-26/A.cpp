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
    int t;
    read(t);
    for (int i = 1; i <= t;i++){
        int n;
        read(n);
        if(n>2){
            puts("YES");
            cout << 2 << endl;
            cout<<(char)getchar()<<" ";
            for (int i = 2;i<=n;i++)
                cout<<(char)getchar();
            cout << endl;
        }else{
            int a=getchar(),b=getchar();
            if(a>=b) puts("NO");
            else{
                puts("YES");
                puts("2");
                cout << (char)a << " " << (char)b << endl;
            }
        }
    }
}