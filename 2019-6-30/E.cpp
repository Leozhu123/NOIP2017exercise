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
const int maxn = 2e5 + 5;
int dep[maxn];
int sz[maxn];
int fa[maxn];
vector<int> G[maxn];
void dfs(int x,int f){
    sz[x] = 1;
    dep[x] = dep[f] + 1;
    if(f == 1)
        fa[x] = x;
    else
        fa[x] = fa[f];
    for (int i = 0; i < G[x].size();i++){
        if(G[x][i] == f)
            continue;
        dfs(G[x][i], x);
        sz[x] += sz[G[x][i]];
    }
}
int main(){
    int n;
    read(n);
    for (int i = 1; i <= n - 1;i++){
        int u,v;
        read(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1,0);
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= n;i ++) {
        sum += dep[i];
    }
    ans = sum;
    for (int i = 2; i <= n;i++){
        ans = max(ans, sum + (n - sz[fa[i]]) * (dep[i] - 1) -
                           sz[i] * (dep[i] - 1));
    }
        cout << ans;
}