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
const int maxn=5005;
LL dp[maxn][maxn];
LL a[maxn];
LL b[maxn];
int n;
LL dfs(int l,int r){
    if(dp[l][r])
        return dp[l][r];
    if(l==r)
        return dp[l][r] = 0;
    if(l+1 ==r)
        return dp[l][r] = 1;
    dp[l][r] = r - l;
    if(a[l] == a[r]){
        dp[l][r] = min(dp[l][r], dfs(l, r - 1));
        dp[l][r] = min(dp[l][r], dfs(l + 1, r));
    }else{
        dp[l][r] = min(dp[l][r], dfs(l, r - 1) + 1);
        dp[l][r] = min(dp[l][r], dfs(l + 1, r) + 1);
    }
    return dp[l][r];
}
int main(){
    read(n);
    for(int i=1;i<=n;i++) read(b[i]);
    int nn=0;
    for (int i = 1;i<=n;i++){
        if(b[i] != b[i-1])
            a[++nn] = b[i];
    }
    n=nn;
    cout << dfs(1,n);
}