#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 100005;
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
int n,m;
int f[maxn], mi[maxn], c[maxn];
vector<int> G[maxn];
void dfs(int x,int minx,int pre){
    int flag = 1;
    minx = min(c[x], minx);
    if(mi[x]>minx){
        mi[x]=minx;
        flag = 0;
    }
    int maxx = max(f[pre], c[x] - minx);
    if(f[x]<maxx){
        f[x] = maxx;
        flag = 0;
    }
    if(flag)
        return;
    for(int i=0;i<G[x].size();i++){
        dfs(G[x][i], minx, x);
    }
}
int main(){
    read(n, m);
    for(int i=0;i<=n;i++){
        mi[i] = INT_MAX;
    }
    for(int i=1;i<=n;i++){
        read(c[i]);
    }
    for (int i = 1; i <= m;i++){
        int a,b,c;
        read(a,b,c);
        G[a].push_back(b);
        if(c==2)
            G[b].push_back(a);
    }
    dfs(1, INT_MAX, 0);
    printf("%d", f[n]);
}