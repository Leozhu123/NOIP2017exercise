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
const int maxn = 5005;
const int inf = (1 << 31) - 1;
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
//        cout << from << ' ' << to << " " << cap << " " << cost << endl;
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
int dx[2]={1,0};
int dy[2] = {0, 1};
int n,k;
inline int f(int x, int y) {
    return (x - 1) * n + y;
}

int main(){
    MMMF mmmf;
    read(n,k);
    int s = n * n * 2 + 1;
    int t = n * n * 2 + 2;
    mmmf.addEdge(s, 1, k, 0);
    mmmf.addEdge(f(n,n)+n*n, t, k, 0);
    for (int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            read(x);
            mmmf.addEdge(f(i,j),f(i,j) + n * n,1,-x);
            mmmf.addEdge(f(i,j),f(i,j) + n * n,INT_MAX,0);
            for(int kkk=0;kkk<2;kkk++){
                int x = i + dx[kkk];
                int y = j + dy[kkk];
                if(x>n || y>n)
                    continue;
                mmmf.addEdge(f(i,j) + n * n, f(x,y), INT_MAX, 0);
            }
        }
    }
    mmmf.maxFlow(s,t,n*n*2+2);
    cout << -mmmf.mincost;
}
