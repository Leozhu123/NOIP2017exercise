#include <iostream>
#include <vector>
#include <cctype>
#include <cstdio>
#include <algorithm>
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
using namespace std;
const int maxn=10005;
int color[maxn],used[maxn];
int sum[2];
vector<int> G[maxn];
bool dfs(int x,int col){
    if(used[x]){
        if(color[x]==col)
            return true;
        else
            return false;
    }
    bool ok=true;
    used[x] = true;
    sum[color[x] = col]++;
    for (int i = 0; i < G[x].size();i++){
        int v=G[x][i];
        ok=ok&&dfs(v, 1 - col);
    }
    return ok;
}
int main(){
    int n,m;
    read(n, m);
    for (int i = 1; i <= m;i++){
        int a,b;
        read(a,b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        if(used[i]) continue;
        sum[0] = sum[1] = 0;
        if(!dfs(i,0)) {
            puts("Impossible");
            return 0;
        }
        ans += min(sum[0], sum[1]);
    }
    printf("%d", ans);
}