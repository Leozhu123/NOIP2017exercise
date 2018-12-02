#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <climits>
#include <cctype>
using namespace std;
#define P pair<int,int>
const int maxn = 10005;
const int inf = (1 << 31) - 1;
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
struct peo{
    int t, l, r;
};
peo a[maxn];
struct Edge{
    int from,to,cap,flow,cost;
    Edge(int from,int to,int cap,int cost){
        this->from=from;
        this->to=to;
        this->cap=cap;
        this->flow=0;
        this->cost = cost;
    }
};

struct MMMF{
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn];
    int p[maxn];
    bool inq[maxn];
    int n, s, t;
    void addEdge(int from,int to,int cap,int cost){
        Edge e1(from,to,cap,cost),e2(to,from,0,-cost);
        edges.push_back(e1);
        edges.push_back(e2);
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int Fini(){
        int x=t;
        int a=inf;
        while (x!=s){
            Edge &e=edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=e.from;
        }
        x=t;
        while (x!=s){
            Edge &e=edges[p[x]];
            e.flow+=a;
            edges[p[x]^1].flow-=a;
            x=e.from;
        }
        return a;
    }
    int maxflow = 0;
    int mincost = 0;
    bool SPFA(){
        queue<int > q;
        for (int i = 1; i <= n;i++) d[i] = inf,inq[i]=0;;
        d[s] = 0;
        q.push(s);
        inq[s]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            inq[x]=0;
            for (int i = 0;i<G[x].size();i++){
                Edge &e = edges[G[x][i]];
                if(e.cap>e.flow){
                    if(d[e.to]>d[x]+e.cost){
                        d[e.to] = d[x] + e.cost;
                        p[e.to] = G[x][i];
                        if(!inq[e.to]){
                            q.push(e.to);
                            inq[e.to]=1;
                        }
                    }
                }
            }
        }
        int a=Fini();
        if(d[t]==inf) return false;
        maxflow+=a;
        mincost += a * d[t];
        return true;
    }
    void maxFlow(int s,int t,int n){
        this->s=s;
        this->t=t;
        this->n=n;
        while(SPFA())
            ;
    }
};
int n, m, K, i, ans = 0;
int D[maxn], Mx[maxn], down[maxn], tim[maxn], S, T;
int main(){
    read(n, m, K);
    for(int i=1;i<n;i++)
        read(D[i]);
    for(int i=1;i<=m;i++){
        read(a[i].t, a[i].l, a[i].r);
        down[a[i].r]++;
        Mx[a[i].l] = max(Mx[a[i].l], a[i].t);
    }
    for (int i = 1;i<n;i++)
        tim[i + 1] = max(tim[i], Mx[i]) + D[i];
    for(int i=1;i<=m;i++){
        ans += tim[a[i].r] - a[i].t;
    }
    S = n * 2 + 1;
    T = n * 2 + 3;
    int S1 = n * 2 + 2;
    MMMF mmmf;
    mmmf.addEdge(S, S1, K, 0);
    for(int i=0;i<n;i++){
        mmmf.addEdge(i, i + n, max(tim[i] - Mx[i], 0), 0);
        mmmf.addEdge(i + n, i + 1, INT_MAX, -down[i + 1]);
        mmmf.addEdge(S1, i + n, D[i], 0);
        mmmf.addEdge(i + 1, T, INT_MAX, 0);
    }
    mmmf.maxFlow(S, T, 2 * n + 3);
    printf("%d\n", ans + mmmf.mincost);
}
