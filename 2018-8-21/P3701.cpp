#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
const int maxn=10005;
const int INF=(1<<31)-1;
using namespace std;
struct Edge{
    int from,to,cap,flow;
    Edge(int from,int to,int cap){
        this->from=from;
        this->to=to;
        this->cap=cap;
        this->flow=0;
    }
};
struct Person{
    int type;
    int life;
    Person(int t=0,int l=0){
        type=t;
        life=l;
    }
}
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
vector<Person>  p1,p2;
int main(){
    int n,m,s,t;
    ISAP maxflow;
    cin>>n>>m;
    int cnt1=0,cnt2=0;
    for (int i=0;i<n;i++){
        string str;
        cin>>str;
        switch(str[0]){
            case 'J':
                p1.push_back(Person(1,0));
                break;
            case 'H':
                p1.push_back(Person(2,0));
                break;
            case 'W':
                p1.push_back(Person(3,0));
                break;
            case 'Y':
                p1.push_back(Person(4,0));
                cnt1++;
                break;
            case 'E':
                p1.push_back(Person(5,0));
                break;
        }

    }
    for (int i=0;i<n;i++){
        string str;
        cin>>str;
        switch(str[0]){
            case 'J':
                p2.push_back(Person(1,0));
                break;
            case 'H':
                p2.push_back(Person(2,0));
                break;
            case 'W':
                p2.push_back(Person(3,0));
                break;
            case 'Y':
                p2.push_back(Person(4,0));
                cnt2++;
                break;
            case 'E':
                p2.push_back(Person(5,0));
                break;
        }
    }
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        if(p1[i].type==1)
            p1[i].life=l+cnt1;
        else
            p1[i].life=l;
    }
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        if(p2[i].type==1)
            p2[i].life=l+cnt2;
        else
            p2[i].life=l;
    }
    s=2*n+1;
    t=2*n+2;
    for(int i=0;i<n;i++){
        maxFlow.addEdge(s,i+1,p1[i].life);
    }
    for(int i=0;i<n;i++){
        maxFlow.addEdge(i+1+n,t,p2[i].life);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p1[i].type==1 && (p2[i].type==2 || p2[i].type==3))
                maxFlow.addEdge(i+1,j+1+n,1);
            if(p1[i].type==2 && (p2[i].type==4 || p2[i].type==5))
                maxFlow.addEdge(i+1,j+1+n,1);
            if(p1[i].type==3 && (p2[i].type==2 || p2[i].type==5))
                maxFlow.addEdge(i+1,j+1+n,1);
            if(p1[i].type==4 && (p2[i].type==1 || p2[i].type==3))
                maxFlow.addEdge(i+1,j+1+n,1);
            if(p1[i].type==5 && (p2[i].type==1 || p2[i].type==4))
                maxFlow.addEdge(i+1,j+1+n,1);
            
        }
    }
    cout<<min(maxflow.MaxFlow(s,t,n),m);
}
