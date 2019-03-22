// luogu-judger-enable-o2
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
const int maxn = 405;
const int maxm = 20005;  
int b[maxn];  
int a[maxn][maxn];
int ss[maxn];
int ans[maxn];
int n,m;
struct Edge{
    int from,to,cap,flow;
    Edge(int from,int to,int cap):from(from),to(to),cap(cap),flow(0){}
};
struct Dinic{
//	bool del[maxm];
    vector<Edge> edge;
    vector<int> G[maxn];
    int maxflow=0;
    void addEdge(int from,int to,int cap){
//    	cout<<from<<" "<<to<<" "<<cap<<endl; 
        Edge e1(from,to,cap);
        Edge e2(to,from,0);
        edge.push_back(e1);
        edge.push_back(e2);
        int m=edge.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int d[maxn],cur[maxn],s,t;
    bool vis[maxn];
    bool BFS(){
    	memset(vis,0,sizeof(vis));
    	memset(d,0,sizeof(d));
        queue<int> q;
        q.push(s);
        d[s]=1;
        vis[s]=true;
        while (!q.empty()){
            int x=q.front();
            q.pop();
            for (int i=0;i<G[x].size();i++){
//				if(del[G[x][i]]) continue;
                Edge &e=edge[G[x][i]];
                if (!vis[e.to] && e.cap>e.flow){
                    d[e.to]=d[x]+1;
                    vis[e.to]=true;
                    q.push(e.to);
                }
            }
    	}
        return vis[t];
    }
    int DFS(int x,int a){
        if (x==t || a==0) return a;
        int flow=0,f;
        for (int &i=cur[x];i<G[x].size();i++){
//			if(del[G[x][i]]) continue;
            Edge &e=edge[G[x][i]];
            if (d[e.to]==d[x]+1 && e.cap>e.flow &&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                flow+=f;
                e.flow+=f;
                edge[G[x][i]^1].flow-=f;
                a-=f;
                if (a==0) break;
            }
        }
        return flow;
    }
    int MaxFlow(int s,int t){
        this->s=s;
        this->t=t;
        while (BFS()){
            memset(cur,0,sizeof(cur));
            maxflow+=DFS(s,INT_MAX);
        }
        return maxflow;
    }               
};
void init(){
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
}
bool check(int mid,Dinic G,int now){
    for(int i=1;i<=m;i++)
        if(a[now][i]>0 && a[now][i]<=ss[now]) G.addEdge(now,n+i,1);
    return G.MaxFlow(n+m+1,n+m+2)>=mid;
}
int main(){
    int T,C;
    read(T,C);
    for(int i=1;i<=T;i++){
        init();
        read(n,m);
        int s=n+m+1,t=n+m+2;
        for(int i=1;i<=m;i++) read(b[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                read(a[i][j]);
        for(int i=1;i<=n;i++) read(ss[i]);
        Dinic g[maxn];
        for(int i=1;i<=n;i++)
            g[0].addEdge(s,i,1);
        for(int i=1;i<=m;i++)
            g[0].addEdge(n+i,t,b[i]);
        //first
        for(int i=1;i<=n;i++){
            g[i]=g[i-1];
            for(int j=1;j<=m;j++){
                vector<int> vd;
                for(int k=1;k<=m;k++){
                    if(a[i][k]==j) 	g[i].addEdge(i,n+k,1),vd.push_back(i),vd.push_back(n+k);
                }
                int flow=g[i].MaxFlow(s,t);
                if(flow==g[i-1].maxflow) for(auto k:vd) g[i].edge.pop_back(),g[i].G[k].pop_back();
                else {
                    ans[i]=j;
                    break;
                }
            }
            cout<<(ans[i]=(ans[i]==0?m+1:ans[i]))<<" ";
        }
        cout<<endl;
        //second
        for(int i=1;i<=n;i++){
            if(ans[i]<=ss[i]) {
                cout<<0<<" ";
                continue;
            }
            int l=1,r=i-1;
			int as=0;
            while(r>=l){
                int mid=(l+r)>>1;
                if(check(mid,g[mid-1],i)) as=mid,l=mid + 1;
                else r = mid - 1;
            }
            if(!check(1,g[0],i)) cout<<i<<" ";
            else cout<<max(i-as,0)<<" ";
        }
        cout<<endl;
    }
}    