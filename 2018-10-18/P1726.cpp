#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <stack>
#define LL long long
using namespace std;
const int maxn = 50005;
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
vector<int> G[maxn];
int tot = 0;
int dfn[maxn],low[maxn];
int id[maxn], all[maxn];
int du[maxn];
int gg = 0;
bool ins[maxn];
stack<int> sta;
vector<int> ans;
void tarjan(int u){
    tot++;
    dfn[u] = low[u] = tot;
    sta.push(u);
    ins[u]=true;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(ins[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    int k;
    if(low[u]==dfn[u]){
        ++gg;
        do{
            k=sta.top();
            sta.pop();
            ins[k] = false;
            id[k] = gg;
            all[gg]++;
        } while (k != u);
    }
}
int main(){
    int n,m;
    read(n,m);
    for(int i=1;i<=m;i++){
        int a,b;
        read(a, b);
        G[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for (int j = 0; j < G[i].size();j++){
            int v = G[i][j];
            if(id[i]!=id[v]){
                du[id[i]]++;
            }
        }
    }
    int tt = 0;
    for(int i=1;i<=gg;i++){
        if(!du[i]){
            if(tt){
                puts("0");
                return 0;
            }
            tt = i;
        }
    }
    printf("%d", all[tt]);
}