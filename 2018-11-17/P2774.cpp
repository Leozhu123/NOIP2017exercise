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
            flow+=DFS(s,INT_MAX);
        }
        return flow;
    }               
};  
int n,m;
LL sum = 0;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};  
int main(){
    Dinic mf;
    read(n, m);
    int s = n * m + 1;
    int t = n * m + 2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;
            read(a);
            sum += a;
            if((i+j)%2==1){
                mf.G.addEage(s, (i - 1) * m + j, a);
            }else{
                mf.G.addEage((i - 1) * m + j, t, a);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)%2==1){
                for (int k = 0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x<=0 || y<=0 ||x>n || y>m)
                        continue;
                    mf.G.addEage((i - 1) * m + j, (x - 1) * m + y, INT_MAX);
                }
            }
        }
    }
    cout << sum - mf.MaxFlow(s, t);
}    
    
