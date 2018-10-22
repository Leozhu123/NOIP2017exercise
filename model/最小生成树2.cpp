#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 5005;
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
int fa[maxn];
int findfa(int x){
    return x == fa[x] ? x : fa[x] = findfa(fa[x]);
}
struct Edge{
    int u,v,c;
    Edge(int u,int v,int c):u(u),v(v),c(c){}
    bool operator<(const Edge &r) const{
        return c < r.c;
    }
};
int n, m;
vector<Edge> edges;
int main(){
    read(n, m);
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        read(a, b, c);
        edges.push_back(Edge(a, b, c));
    }
    sort(edges.begin(), edges.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0;i<edges.size();i++){
        Edge &e=edges[i];
        int fa1 = findfa(e.u);
        int fa2 = findfa(e.v);
        if(fa1==fa2)
            continue;
        ans += e.c;
        fa[fa1]=fa2;
        cnt++;
        if(cnt==n-1)
            break;
    }
    printf("%d", ans);
}