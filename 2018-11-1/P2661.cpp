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
const int maxn=200005;
vector<int> G[maxn];
int dfn[maxn], low[maxn];
bool ins[maxn];
int col=0;
int sum[maxn];
int tot = 0;
stack<int> s;
void tarjan(int x){
    dfn[x] = low[x] = ++tot;
    s.push(x);
    ins[x] = true;
    for (int i = 0; i < G[x].size();i++){
        int v=G[x][i];
        if(!dfn[v]){
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }else if(ins[v]){
            low[x] = min(low[x], dfn[v]);
        }
    }
    if(dfn[x]==low[x]){
        int k;
        col++;
        do{
            k=s.top();
            s.pop();
            ins[k] = false;
            sum[col]++;
        } while (k != x);
    }
}
int main(){
    int n;
    read(n);
    for (int i = 1; i <= n;i++){
        int t;
        read(t);
        G[i].push_back(t);
    }
    for (int i =1 ; i <= n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int ans=INT_MAX;
    for (int i = 1; i <= col;i++){
        if(sum[i]>1)
            ans = min(ans, sum[i]);
    }
    printf("%d", ans);
}