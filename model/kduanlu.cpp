#include <iostream>
#include <queue>
#include <vector>

#define P pair<double,int>
using namespace std;
struct edge{
	int v;
	double cost;
	edge(int v=0,double cost=0):v(v),cost(cost){}
};
const int maxn=5005;
const int inf=(1<<31)-1;
vector <edge> G[maxn],rG[maxn];
double d[maxn];
int n,m;
//int cnt[maxn];
double e;

void dijkstra(int s){
	for(int i=1;i<=n;i++){
		d[i]=inf;
	}
	priority_queue<P ,vector<P> ,greater<P > > q;
	q.push(P(0,s));
	d[s]=0;
	while(!q.empty()){
		P x=q.top();
		q.pop();
		int u=x.second;
		if(x.first>d[u]) continue;
		for(int i=0;i<rG[u].size();i++){
			int v=rG[u][i].v;
			if(d[v]>d[u]+rG[u][i].cost){
				d[v]=d[u]+rG[u][i].cost;
				q.push(P(d[v],v));
			}
		}
	}
}
int astar(int s){
	const double INF=e/d[s];
	priority_queue<P ,vector<P> ,greater<P > > q;
	q.push(P(s,d[s]));
	int ans=0;
	while(!q.empty()){
		P x=q.top();
		q.pop();
		if(x.first>e) return ans;
//		if(++cnt[x.second]>INF) continue;
		if(x.second==n){
			cout<<e<<endl;
			e-=x.first;
			ans++;
			continue;
		}
		for(int i=0;i<G[x.second].size();i++){
			int v=G[x.second][i].v;
			q.push(P(x.first - d[x.second] + G[x.second][i].cost + d[v],v));
		}
	}
	return ans;
}
int main(){
	cin>>n>>m>>e;
	int ans=0;
	for(int i=0;i<m;i++){
		int u,v;
		double c;
		cin>>u>>v>>c;
		G[u].push_back(edge(v,c));
		rG[v].push_back(edge(u,c));
	}
	dijkstra(n);
	cout<<astar(1)-1;
	return 0;
}
