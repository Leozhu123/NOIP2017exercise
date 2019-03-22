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
const int maxn=505;
char a[maxn][maxn];
int main(){
    int n;
    read(n);
    for(int i=1;i<=n;i++)
        for (int j = 1;j<=n;j++)
            cin>>a[i][j];
    int ans=0;
    for (int i = 1; i <= n;i++){
        for (int j = 1;j<=n;j++){
            if(a[i][j]=='X' && a[i-1][j-1]=='X' && a[i+1][j+1]=='X' && a[i+1][j-1]=='X' &&a[i-1][j+1]=='X')
                ans++;
        }
    }
    cout << ans;
}