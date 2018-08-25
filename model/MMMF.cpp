// luogu-judger-enable-o2
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define P pair<int,int>
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
int main(){
    int n,m,s,t;
    MMMF maxflow;
    cin>>n>>m>>s>>t;
    for (int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        maxflow.addEdge(a,b,c,d);
    }
    maxflow.maxFlow(s,t,n);
    cout << maxflow.maxflow << " " << maxflow.mincost;
}
