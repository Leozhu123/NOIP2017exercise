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
#define Pii pair<int,int>
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
int t;
int a[10][100];
int calc(vector<int> c){
    int n = c.size();
    if(n == 1) return a[0][c[0]];
    if(n==2){
        int ans = 0;
        for (int i2 = 0; i2 < n;i2++){
            int tmp = 0;
            for(int )
        }
    }
    if(n==3)
    if(n == 4)
}
int main(){
    read(t);
    while(t--){
        int n,m;
        read(n, m);
        memset(a, 0, sizeof(a));
        for (int i = 1;i<=n;i++)
            for (int j = 1;j<=m;j++)
                read(a[i][j]),a[0][j] = max(a[0][j],a[i][j]);
        vector<Pii> so;
        for (int i = 1;i<=m;i++){
            so.push_back(Pii(a[0][i], i));
        }
        vector<int> c;
        for (int i = 0; i < n;i++)
            c.push_back(so[i].second);
        cout << calc(c);
    }
}