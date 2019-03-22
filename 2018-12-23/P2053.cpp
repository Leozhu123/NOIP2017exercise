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
    MMMF mmmf;
    int n,m;
    read(m,n);
	int S=n*m+n+1;
	int T=n*m+n+2;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++){
			int t;
			read(t);
			for(int k=1;<=n;i++) mmmf.addEdge(m*n+i,(j-1)*n+k,1,k*t);
		}
	for(int i=1;i<=n;i++) mmmf.addEdge(S,n*m+i,1,0);
	for(int i=1;i<=n*m;i++) mmmf.addEdge(i,T,1,0);
	mmmf.maxFlow(S,T,n*m+n+2);
	printf("%.2lf",1.0*mmmf.mincost/n);
}

















