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
const int maxn=100005;
const int maxm=200005;
int head[maxn];
int u[maxm],v[maxm],w[maxm],nxt[maxm];
int tot;
void ae(int from,int to,int wei){
    u[++tot]=from;
    v[tot]=to;
    w[tot] = wei;
    nxt[tot]=head[from];
    head[from] = tot;
}
int n, m, s;
int dis[maxn];
int main(){
    read(n, m,s);
    for(int i=1;i<=n;i++)
        dis[i] = INT_MAX;
    for(int i=1;i<=m;i++){
        int u,v,w;
        read(u,v,w);
        ae(u,v,w);
    }
    dis[s]=0;
    priority_queue<P,vector<P >,greater<P > > q;
    q.push(P(0, 1));
    while(!q.empty()){
        P x=q.top();
        q.pop();
        if(dis[x.second]<x.first) continue;
        for (int i = head[x.second]; i;i=nxt[i]){
            if(dis[v[i]]>dis[x.second]+w[i]){
                dis[v[i]]=dis[x.second]+w[i];
                q.push(P(dis[v[i]], v[i]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ", dis[i]);
    }
}