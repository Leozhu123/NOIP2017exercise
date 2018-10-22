#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <climits>
#define P system("pause")
#define LL long long
const LL maxn=1005;
const LL INF=1e15;
using namespace std;
struct Eage{
    LL from,to,cap,flow;
    Eage(LL from,LL to,LL cap):from(from),to(to),cap(cap),flow(0){}
};
struct Graph{
    vector<Eage> eage;
    vector<LL> map[maxn];
    void addEage(LL from,LL to,LL cap){
        //cout << from << " " << to << " " << cap << endl;
        Eage e1(from,to,cap);
        Eage e2(to,from,0);
        eage.push_back(e1);
        eage.push_back(e2);
        LL m=eage.size();
        map[from].push_back(m-2);
        map[to].push_back(m-1);
    }
};
struct Dinic{
    Graph G;
    LL d[maxn],cur[maxn],s,t;
    bool vis[maxn];
    bool BFS(){
    	memset(vis,0,sizeof(vis));
    	memset(d,0,sizeof(d));
        queue<LL> q;
        q.push(s);
        d[s]=1;
        vis[s]=true;
        while (!q.empty()){
            LL x=q.front();
            q.pop();
            for (LL i=0;i<G.map[x].size();i++){
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
    LL DFS(LL x,LL a){
        if (x==t || a==0) return a;
        LL flow=0,f;
        for (LL &i=cur[x];i<G.map[x].size();i++){
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
    LL MaxFlow(LL s,LL t){
        this->s=s;
        this->t=t;
        LL flow=0;
        while (BFS()){
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }               
};    
LL A[maxn], B[maxn];
LL g[55][55];
LL n,m;
LL sum = 0;
bool check(LL t){
    Dinic maxflow;
    for(LL i=1;i<=m;i++){
        maxflow.G.addEage(1, i + 2, B[i] * t);
    }
    for(LL i=1;i<=m;i++){
        for(LL j=1;j<=n;j++){
            if(g[i][j])
                maxflow.G.addEage(i+2, j+m+2, INF);
            //cout << INF << endl;
        }
    }
    for(LL i=1;i<=n;i++){
        maxflow.G.addEage(i + m + 2, 2, A[i] * 10000);
    }
    LL ans = maxflow.MaxFlow(1,2);
    //cout << ans << endl;
    //P;
    return ans < sum*10000;
}
int main(){
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin >> A[i];
        sum += A[i];
    }
    for(LL  i=1;i<=m;i++){
        cin >> B[i];
    }
    for (LL i = 1; i <= m;i++){
        for(LL j=1 ; j<=n;j++){
            cin >> g[i][j];
        }
    }
    LL l = 1;
    LL r=10000000;
    while (l+5<r){
        LL mid=(l+r)>>1;
        if(check(mid)){
            l = mid;
        }else {
            r = mid;
        }
    }
    for (LL i = l; i <= r;i++){
        if(check(i)){
            printf("%.4lf", (double)i / 10000);
            return 0;
        }
    }
}
