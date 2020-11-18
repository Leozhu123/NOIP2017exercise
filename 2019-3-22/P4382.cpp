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
const int maxn = 605;
int b[maxn];  
int a[maxn][maxn][15];
int tcnt[maxn][maxn];
int ideal[maxn];
int ans[maxn];
int n,m;
struct Edge{
    int from,to,cap,flow;
    Edge(int from,int to,int cap):from(from),to(to),cap(cap),flow(0){}
};
struct Dinic{
    vector<Edge> edge;
    vector<int> G[maxn];
    int maxflow=0;
    void addEdge(int from,int to,int cap){
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
        int ans = 0;
        while (BFS()){
            memset(cur,0,sizeof(cur));
            ans+=DFS(s,INT_MAX);
        }
        return ans;
    }  
    void de(int x){
        G[x].pop_back();
        edge.pop_back();
    }          
    void clear(){
        for (int i = 0; i < maxn;i++)
            G[i].clear();
    }   
};

Dinic g[maxn];

void init(){
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    memset(ideal,0,sizeof(ideal));
    for (int i = 0; i <maxn;i++)
        g[i].clear();
} 

int s,t;

bool check(int x,int pos,Dinic G){
    G.addEdge(s, x, 1);
    for (int i = 1; i <= ideal[x];i++){
        for (int j = 1; j <= tcnt[x][i];j++){
            G.addEdge(x, a[x][i][j] + n, 1);
        }
    }
    return G.MaxFlow(s, t);
}

int main(){
    int T,C;
    read(T,C);
    for(int i=1;i<=T;i++){
        read(n,m);
        s=n+m+1,t=n+m+2;
        for(int i=1;i<=m;i++) read(b[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                int x;
                read(x);
                if(x)
                    a[i][x][++tcnt[i][x]] = j;
            }
        for(int i=1;i<=n;i++) read(ideal[i]);
        for(int i=1;i<=m;i++)
            g[0].addEdge(n+i,t,b[i]);
        //first
        for(int i=1;i<=n;i++){
            g[i]=g[i-1];
            ans[i] = m + 1;
            g[i].addEdge(s,i,1);
            for(int j=1;j<=m;j++){
                if(tcnt[i][j]==0)
                    continue;
                for(int k=1;k<=tcnt[i][j];k++){
                    g[i].addEdge(i, a[i][j][k] + n, 1);
                }
                int flow=g[i].MaxFlow(s,t);
                if(flow){
                    ans[i] = j;
                }else{
                    for (int k = 1; k <= tcnt[i][j];k++){
                        g[i].de(i);
                        g[i].de(a[i][j][k] + n);
                    }
                }
            }
            printf("%d ", ans[i]);
        }
        puts("");
        //second
        for(int i=1;i<=n;i++){
            if(ans[i]<=ideal[i]) {
                printf("0 ");
                continue;
            }
            int l=1,r=i-1;
			int as=-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(check(i,mid,g[mid-1])) as=mid,l=mid + 1;
                else r = mid - 1;
            }
            if(as!=-1)
                printf("%d ", i - as);
            else
                printf("%d ", i);
        }
        puts("");
        init();
    }
}    