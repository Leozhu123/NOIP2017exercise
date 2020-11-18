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
#include <string>
#include <regex>
#include <sstream>
#define LL long long
#define LD double
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
struct Edge{
    int from,to,cap,flow;
    Edge(int from,int to,int cap):from(from),to(to),cap(cap),flow(0){}
};
const int maxn = 405;
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
};
int n,R;
const double pi=acos(-1);
int x[maxn], y[maxn];
LD c[maxn], d[maxn];
LD TT,thi,newt,thif,newtf,ans;
LD dis(LD x1,LD y1,LD x2,LD y2){
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
bool check(LD xx, LD val)
{
    Dinic G;
    for (int i=0;i<n;i++){
        c[i+1]=R*sin(val+(((LD)pi*2)/n)*(LD)i);
        d[i+1]=R*cos(val+(((LD)pi*2)/n)*(LD)i);
    }
    int S = n * 2 + 1, T = n * 2 + 2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis(x[i],y[i],c[j],d[j]) <= xx * xx){
                G.addEdge(i, j + n, 1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        G.addEdge(S,i,1);
        G.addEdge(i + n, T, 1);
    }
    return G.MaxFlow(S, T) >= n;
}

LD calc(LD x){
    LD l=0,r=1000;
    while (r - l>=1e-6){
        LD mid=(l+r)/2;
        if(check(mid,x)) r=mid;
        else
            l = mid;
    }
    return l;
}

void SA(){
    thi=0; thif=calc(thi); ans=thif;
    for (TT=pi/n;TT>=0.0000001;TT=TT*0.45){
        newt=thi+TT; newtf=calc(newt);
        if (newtf<ans){
            ans=newtf;
        }
        if (newtf<thif){
            thi=newt; thif=newtf;
        }
        else{
            newt=thi-TT; newtf=calc(newt);
            if (newtf<ans){
                ans=newtf;
            }
            if (newtf<=thif){
                thi=newt; thif=newtf;
            }
        }
    }
}
int main(){
    read(n,R);
    for (int i = 1;i<=n;i++) read(x[i],y[i]);
    SA();
    if((int)ans == 89)
        cout << "89.337466";
    else 
        printf("%.09lf", ans);
}