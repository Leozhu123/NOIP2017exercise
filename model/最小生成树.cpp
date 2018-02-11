#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>>
const int maxn=10010;
const int INF=(1<<30)-1;
using namespace std; 
struct Edge{
    int from,to,cost;
    Edge(int from,int to,int cost):from(from),to(to),cost(cost){}
};    
vector <Edge> edges;
vector<int> G[maxn];
void addEdge(int a,int b,int c){
    Edge e1(a,b,c),e2(b,a,c);
    edges.push_back(e1);
    edges.push_back(e2);
    int m=edges.size();
    G[a].push_back(m-2);
    G[b].push_back(m-1);
}    
int d[maxn];
bool vis[maxn];
int main(){
    int n,m;
    for (int i=1;i<10000;i++) d[i]=INF;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        addEdge(a,b,c);
}
    int x=1;
    d[x]=0;
    vis[x]=true;
    int ans=0;
    for (int i=0;i<n;i++){
        //cout<<d[x]<<','<<x<<endl;
        ans+=d[x];
        for (int i=0;i<G[x].size();i++){
            Edge &e=edges[G[x][i]];
           // cout<<d[e.to]<<'    '<<e.cost<<endl;
            d[e.to]=min(d[e.to],e.cost);
        }
        int tmp=INF,tmpp;
        for (int i=1;i<=n;i++){
        //	cout<<tmp<<' '<<d[i]<<endl;
            if (tmp>d[i] && !vis[i]) { tmpp=i; tmp=d[i];}
        }
        x=tmpp;
        vis[tmpp]=true;
    }    
    cout<<ans;
}
