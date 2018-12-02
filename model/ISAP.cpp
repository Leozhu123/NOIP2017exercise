#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
const int maxn=10005;
const int INF=(1<<31)-1;
using namespace std;
struct Edge{
    int from,to,cap,flow;
    Edge(int from,int to,int cap):from(from),to(to),cap(cap),flow(0){}
};
struct ISAP{
    vector<Edge> edges;
    vector<int> G[maxn];
    void addEdge(int from,int to,int cap){
        Edge e1(from,to,cap),e2(to,from,0);
        edges.push_back(e1);
        edges.push_back(e2);
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int num[maxn],s,t,cur[maxn],d[maxn],p[maxn],n;
    bool vis[maxn];
    void BFS(){
        queue<int> q;
        q.push(t);
        d[t]=0;
        vis[t]=true;
        while (!q.empty()){
            int x=q.front();
            q.pop();
            for (int i=0;i<G[x].size();i++){
                Edge &e=edges[G[x][i]];
                if (!vis[e.to]){
                    vis[e.to]=true;
                    q.push(e.to);
                    d[e.to]=d[x]+1;
                }
            }
        }
    }
    int Fini(){
        int x=t;
        int a=INF;
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
    int MaxFlow(int s,int t,int n){
        this->s=s;
        this->t=t;
        this->n=n;
        memset(cur,0,sizeof(cur));
        memset(num,0,sizeof(num));
        memset(vis,0,sizeof(vis));
        BFS();
        for (int i=1;i<=n;i++) num[d[i]]++;
        int x=s,flow=0;
        while (d[s]<n){
            if (x==t){
                flow+=Fini();
                x=s;
            }
            bool ok=false;
            for (int i=0;i<G[x].size();i++){
                Edge &e=edges[G[x][i]];
                if (e.cap>e.flow && d[e.to]==d[x]-1){
                    cur[x]=i;
                    ok=true;
                    p[e.to]=G[x][i];
                    x=e.to;
                    break;
                }
            }
            if (!ok){
                int m=n-1;
                for (int i=0;i<G[x].size();i++){
                    Edge &e=edges[G[x][i]];
                    if (e.cap>e.flow) m=min(m,d[e.to]);
                }
                if (--num[d[x]]==0) break;
                num[d[x]=m+1]++;
                if (x!=s) x=edges[p[x]].from;
            }
        }
        return flow;
    }
};    
int main(){
    int n,m,s,t;
    ISAP maxflow;
    cin>>n>>m>>s>>t;
    for (int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        maxflow.addEdge(a,b,c);
    }
    cout<<maxflow.MaxFlow(s,t,n);
}
