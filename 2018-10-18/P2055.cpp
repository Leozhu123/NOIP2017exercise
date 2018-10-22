#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <stack>
#define LL long long
using namespace std;
const int maxn = 50005;
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
bool school[maxn],home[maxn];
int main(){
    int T;
    read(T);
    while(T--){
        memset(school, 0, sizeof(school));
        memset(home, 0, sizeof(home));
        Dinic maxflow;
        int n;
        read(n);
        int s=(n<<1)+1;
        int t = s + 1;
        int need = 0;
        for(int i=1;i<=n;i++){
            int x;
            read(x);
            if(x){
                school[i] = 1;
                maxflow.G.addEage(i + n, t, 1);
            }
        }
        for(int i=1;i<=n;i++){
            int x;
            read(x);
            if(school[i]&&x)
                home[i] = 1;
            if((school[i]&&!x)||(!school[i])){
                maxflow.G.addEage(s,i,1);
                need++;
            }
        }
        for(int i=1;i<=n;i++){
            for (int j = 1; j <= n;j++){
                int x;
                read(x);
                if(x || i==j){
                    maxflow.G.addEage(i, j + n, 1);
                }
            }
        }
        int mf = maxflow.MaxFlow(s, t);
        if(mf>=need)puts("^_^");
        else
            puts("T_T");
    }
}    
    
