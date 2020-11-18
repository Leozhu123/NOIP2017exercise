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
const int maxn = 1e5+5;
vector<int> G[maxn];
int f[maxn][20];
int dep[maxn];
void dfs(int x,int fa){
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;
    for (int i = 1; i <= 19;i++){
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for(auto v:G[x]){
        if(v == fa) continue;
        dfs(v, x);
    }
}
int lca(int x,int y){
    if(dep[x] > dep[y])
        swap(x, y);
    for (int i = 19; i >= 0;i--){
        if(dep[f[y][i]] >= dep[x]) y = f[y][i];
    }
    if(x == y) return x;
    for (int i = 19; i >= 0;i--){
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int calc(int x,int y){
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
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
    dfs(1, 0);
    int q;
    read(q);
    while(q--){
        int x,y,a,b,k;
        read(x,y,a,b,k);
        int dis = calc(a,b);
        if(dis <=k && (dis&1) == (k&1)){
            cout << "YES" << endl;
            continue;
        }
        dis = min(1+calc(a,x) + calc(b,y),1+calc(a,y)+calc(b,x));
        if(dis<=k && (dis&1) == (k&1)){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}