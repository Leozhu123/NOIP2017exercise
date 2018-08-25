#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

const int maxn = 200005;
const int INF = (1 << 29) - 1;
using namespace std;
struct Edge{
    int u, v, len, h;
    Edge(int a,int b,int c,int d){
        u=a;
        v=b;
        len=c;
        h = d;
    }
    Edge(){
        u = v = len = h = 0;
    }
};
int d[maxn],sum[maxn];
vector<Edge> G[maxn];
void SPFA(){
    int S = 1;
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=0;i<G[x].size();i++){
            int to=G[x][i].v;
            if(d[x]+G[x][i].len<d[to]){
                d[to]=d[x]+G[x][i].len;
                q.push(to);
            }
        }
    }
}
void init(){
    for(int i=0;i<maxn;i++){
        G[i].clear();
        d[i] = INF;
        sum[i] = 0;
    }
}
int main(){
    freopen("return.in","r",stdin);
    freopen("return.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int caa=0;caa<T;caa++){
        init();
        int n,m;
        int lastans = 0;
        bool isFirst = true;
        bool isSecond = true;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v,l,h;
            scanf("%d%d%d%d",&u,&v,&l,&h);
            if(h!=1)
                isFirst = false;
            if(v!=u+1)
                isSecond = false;
            G[u].push_back(Edge(u,v,l,h));
            G[v].push_back(Edge(v, u, l, h));
        }
        int Q, K, S;
        scanf("%d%d%d", &Q, &K, &S);

        if(isFirst){
            SPFA();
            for (int i = 0; i < Q;i++){
                int v,p;
                scanf("%d%d",&v,&p);
                v = (v + K * lastans - 1) % n + 1;
                p = (p + K * lastans - 1) % n + 1;
                if(p==0){
                    printf("0\n");
                }else{
                    printf("%d\n", d[v]);
                }
            }
        }else if(isSecond){
            sum[1] = 0;
            for(int i=2;i<=n;i++){
                sum[i] = sum[i-1]+G[i][0].len;
            }
            for (int i = 0; i < Q;i++){
                int v,p;
                scanf("%d%d",&v,&p);
                v = (v + K * lastans - 1) % n + 1;
                p = (p + K * lastans - 1) % n + 1;
                int j;
                for (j = v; j >= 1;j--){
                    if(G[j][0].h<=p)
                        break;
                }
                printf("%d\n", sum[j]);
            }
        }
    }
}