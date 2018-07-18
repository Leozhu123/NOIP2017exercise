#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
const int maxn = 10005;
const int INF = (1 << 31) - 1;
using namespace std;
int v[maxn],d[maxn],S;
vector<pair<int,int> > G[maxn];
void SPFA(){
    queue<int> q;
    q.push(S);
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=0;i<G[x].size();i++){
            int to=G[x][i].first;
            if(d[x]+G[x][i].second<d[to]){
                d[to]=d[x]+G[x][i].second;
                q.push(to);
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
    SPFA();
    for (int i=1;i<=n;i++){
        cout << d[i] << " ";
    }
}