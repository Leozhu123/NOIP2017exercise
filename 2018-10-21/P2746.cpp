#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cstring>
#define CHK //printf("function: %s at line %d\n",__FUNCTION__,__LINE__)
using namespace std;
const int maxn = 505;
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
int dfn[maxn],low[maxn];
int tot=0,col=0;
int color[maxn];
int in[maxn], out[maxn];
bool ins[maxn];
stack<int> s;
void tarjan(int x){
    CHK;
    tot++;
    dfn[x]=low[x]=tot;
    s.push(x);
    ins[x]=true;
    for(int i=0;i<G[x].size();i++){
        CHK;
        if(!dfn[G[x][i]]){
            tarjan(G[x][i]);
            low[x] = min(low[x], low[G[x][i]]);
        }else if(ins[G[x][i]]){
            low[x] = min(low[x], dfn[G[x][i]]);
        }
    }
    if(low[x]==dfn[x]){
        int k;
        col++;
        do{
            k=s.top();
            s.pop();
            ins[k]=false;
            color[k] = col;
        } while (k != x);
    }
}
int n;
int main(){
    read(n);
    for(int i=1;i<=n;i++){
        int x;
        read(x);
        while(x!=0){
            G[i].push_back(x);
            read(x);
        }
    }
    for (int i = 1; i <= n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    CHK;
    for(int i=1;i<=n;i++){
        for (int j = 0;j<G[i].size();j++){
            if(color[i]!=color[G[i][j]]){
                out[color[i]]++;
                in[color[G[i][j]]]++;
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=col;i++){
        if(in[i]==0) ans1++;
        if(out[i]==0)
            ans2++;
    }
    if(col==1) cout<<1<<endl<<0;
    else
        cout << ans1 << endl
             << max(ans1, ans2);
}