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
const int maxn = 10000005;
bool vis[maxn];
LL sum[maxn];
int prim[maxn];
int mu[maxn],g[maxn];
int cnt;
void init(){
    mu[1]=1;
    for(int i=2;i<=1e7;i++){
        if(!vis[i]){
            mu[i] = -1;
            prim[++cnt] = i;
        }
        for(int j=1;j<=cnt&&prim[j]*i<=1e7;j++){
            vis[i * prim[j]] = 1;
            if(i%prim[j]==0)
                break;
            else
                mu[prim[j] * i] = -mu[i];
        }
    }
    for(int j=1;j<=cnt;j++)
        for (int i = 1; i * prim[j] <= 1e7;i++)
            g[i * prim[j]] += mu[i];
    for(int i=1;i<=1e7;i++)
        sum[i] = sum[i - 1] + g[i];
}
int n,m;
int main(){
    int t;
    read(t);
    init();
    while(t--){
        read(n, m);
        if(n>m) swap(n,m);
        LL ans = 0;
        for (int l = 1, r; l <= n;l=r+1){
            r = min(n / (n / l), m / (m / l));
            ans += (LL)(n / l) * (m / l) * (sum[r] - sum[l - 1]);
        }
        cout << ans << endl;
    }
}