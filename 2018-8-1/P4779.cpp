#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#define P pair<int,int>
const int maxn = 100005;
const int INF = (1 << 31) - 1;
using namespace std;
int v[maxn],d[maxn],S;
vector<P > G[maxn];
priority_queue<P, vector<P >, greater<P > > q;
void Dji(){
    q.push(P(d[S],S));
    while(!q.empty()){
        P x=q.top();
        q.pop();
        if(x.first>d[x.second])
            continue;
        int u=x.second;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].first;
            if(d[v]>d[u]+G[u][i].second){
                d[v]=d[u]+G[u][i].second;
                q.push(P(d[v],v));
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m>>S;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back(pair<int,int>(b, c));
    }
    for (int i=0;i<=n;i++){
        d[i] = INF;
    }
    d[S] = 0;
    Dji();
    for (int i=1;i<=n;i++){
        cout << d[i] << " ";
    }
}