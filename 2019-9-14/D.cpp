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
const int maxn = 1e5 + 5;
vector<int> G[maxn];
bool vis[maxn];
int ans = 0;
void dfs(int x){
    vis[x] = true;
    for (int i = 0; i < G[x].size();i++){
        int v = G[x][i];
        if(!vis[v]){
            dfs(v);
            ans++;
        }
    }
}
int main(){
    int n,k;
    read(n,k);
    for (int i = 1;i<=k;i++){
        int x,y;
        read(x, y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1;i<=n;i++){
        if(!vis[i]) {
            dfs(i);
        }
    }
    cout << k - ans;
}