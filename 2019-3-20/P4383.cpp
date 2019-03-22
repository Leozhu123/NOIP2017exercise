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
#include <regex>
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

const int maxn = 3e5 + 5;
struct Edge{
    int u,v,w;
    Edge(int u,int v,int w):u(u),v(v),w(w){}
};

struct dat{
    LL x,y;
    dat(LL x = 0,LL y = 0):x(x),y(y){}
    dat operator + (const dat &o) const {return (dat){x+o.x,y+o.y};}
    bool operator < (const dat &o) const {return x==o.x? y>o.y : x<o.x;}
    dat operator + (int o) {return (dat){x+o,y};}
};

vector<Edge> G[maxn];

dat dp[maxn][3];

void dfs(int u,int fa,int mid){
    dp[u][2]=dat(-mid,1);
    dp[u][1]=dat(-mid,1);
    dp[u][0] = dat(0, 0);
    for(int i=0;i<G[u].size();i++){
        Edge &e=G[u][i];
        if(e.v == fa) continue;
        dfs(e.v, u, mid);
        dat mx = max(dp[e.v][0], max(dp[e.v][1], dp[e.v][2]));
        dp[u][2] = max(dp[u][2] + mx , dp[u][1] + dp[e.v][1] + e.w + dat(mid,-1));
        dp[u][1] = max(dp[u][1] + mx, dp[u][0] + dp[e.v][1] + e.w);
        dp[u][0] = max(dp[u][0], dp[u][0] + mx);
    }
}

bool check(int mid,int k){
    dfs(1,0,mid);
    dat mx = max(dp[1][0], max(dp[1][1], dp[1][2]));
    return mx.y <= k;
}

int main(){
    int n,k;
    read(n,k);
    k++;
    for (int i = 1; i < n;i++){
        int u,v,w;
        read(u,v,w);
        G[u].push_back(Edge(u,v,w));
        G[v].push_back(Edge(v, u, w));
    }
    int l=-1e9,r=1e9;
    LL ans = 0;
    while(l <= r){
        int mid=(l+r)>>1;
        if(check(mid,k)) ans = mid,r = mid - 1;
        else
            l = mid + 1;
    }
    dfs(1, 0, ans);
    dat mx=max(dp[1][0],max(dp[1][1],dp[1][2]));
    ans = mx.x + (LL)ans * k;
    cout << ans;
}