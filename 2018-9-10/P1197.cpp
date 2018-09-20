#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=400005;
struct Edge{
    int u,v;
    Edge(int u,int v):u(u),v(v){}
};
int fa[maxn];
vector<Edge> edges;
vector<int> G[maxn];
int out[maxn];
int d[maxn];
bool broken[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fa1=find(x),fa2=find(y);
	if(fa1==fa2) return false;
	fa[fa1]=fa2;
	return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(Edge(x,y));
        edges.push_back(Edge(y,x));
        G[x].push_back(edges.size()-2);
        G[y].push_back(edges.size()-1);
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
		cin>>d[i];
		broken[d[i]]=true;
    }
    int ans=n-k;
    for(int i=0;i<m*2;i++){
    	Edge &e=edges[i];
    	if(!broken[e.u] && !broken[e.v]){
    		if (merge(e.u,e.v)) ans--;
    	}
    }
    out[k+1]=ans;
    for(int i=k;i>=1;i--){
        int u=d[i];
        broken[u]=false;
        ans++;
        for(int j=0;j<G[u].size();j++){
            Edge &e=edges[G[u][j]];
            if(!broken[e.v] && merge(e.u,e.v)){
            	ans--;
            }
        }
        out[i]=ans;
    }
    for(int i=1;i<=k+1;i++){
        cout<<out[i]<<endl;
    }
}
