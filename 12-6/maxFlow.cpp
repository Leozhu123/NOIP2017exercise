#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
const int maxn=10005;
const int INF=1<<31-1;
using namespace std;
struct Eage{
    int from,to,cap,flow;
    Eage(int from,int to,int cap):from(from),to(to),cap(cap),flow(0){}
};
struct Graph{
    vector<Eage> eage;
    vector<int> map[maxn];
    void addEage(int from,int to,int cap){
        Eage e1(from,to,cap);
        Eage e2(to,from,0);
        eage.push_back(e1);
        eage.push_back(e2);
        int m=eage.size();
        map[from].push_back(m-2);
        map[to].push_back(m-1);
    }
};
struct Dinic{
    Graph G;
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
            for (int i=0;i<G.map[x].size();i++){
                Eage &e=G.eage[G.map[x][i]];
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
        for (int &i=cur[x];i<G.map[x].size();i++){
            Eage &e=G.eage[G.map[x][i]];
            if (d[e.to]==d[x]+1 && e.cap>e.flow &&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                flow+=f;
                e.flow+=f;
                G.eage[G.map[x][i]^1].flow-=f;
                a-=f;
                if (a==0) break;
            }
        }
        return flow;
    }
    int MaxFlow(int s,int t){
        this->s=s;
        this->t=t;
        int flow=0;
        while (BFS()){
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }               
};    
int main(){
    int n,m,s,t;
    Dinic maxflow;
    cin>>n>>m>>s>>t;
    for (int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        maxflow.G.addEage(a,b,c);
    }
    cout<<maxflow.MaxFlow(s,t);
}    
    
