#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
#define P pair<pair<int,int>,int>
#define MP make_pair
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
const int maxn=3e5+5;
int n, m;
vector<int> G[maxn];
bool vis[maxn];
priority_queue<int,vector<int>,greater<int> > q;
int main(){ 
    int n,m;
    read(n,m);
    for (int i = 1; i <= m;i++){
        int u, v;
        read(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        cout<<u<<" ";
        for (int i = 0; i < G[u].size();i++){
            int v=G[u][i];
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }
}