#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 1000005;
const int p = 100003;
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
int ans[maxn];
bool inq[maxn];
int dis[maxn];
vector<int> G[maxn];
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)
        dis[i] = (1<<30);
    for (int i = 1; i <= m; i++)
    {
        int x,y;
        read(x,y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ans[1] = 1;
    inq[1] = 1;
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=0;
        for (int i = 0;i<G[x].size();i++){
            int v=G[x][i];
            if(dis[v]>dis[x]+1){
                dis[v] = dis[x] + 1;
                ans[v] = ans[x];
                if(!inq[v]){
                    q.push(v);
                    inq[v] = 1;
                }
            }else if(dis[v]==dis[x]+1){
                ans[v]+=ans[x];
                ans[v] %= p;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n", ans[i]);
    }
}