#include <iostream>
#include <cstdio>
#include <cctype>
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
#define LL long long
int n,m;
const int maxn=1005;
int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a % b);
}
int a[maxn],f[maxn][maxn];
int main(){
    read(n,m);
    for (int i = 1; i <= n;i++){
        read(a[i]);
        f[i][i] = a[i];
    }
    for (int i = n-1; i >=1;i--){
        for (int j = i+1; j <= n;j++){
            if(i==j) continue;
            f[i][j] = gcd(f[i][i], f[i + 1][j]);
        }
    }
    for (int i = 1;i<=m;i++){
        int a,b;
        read(a,b);
        printf("%d\n", f[a][b]);
    }
}