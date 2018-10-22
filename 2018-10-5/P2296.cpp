#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
const int maxn=10005;
vector<int> G[maxn];
bool mark1[maxn],mark2[maxn];
int n,m,st,ed;
int ans[maxn];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int a,b;
        cin >> a >> b;
        if(a==b)
            continue;
        G[b].push_back(a);
    }
    cin >> st >> ed;
    mark1[ed] = 1;
    queue<int> q;
    q.push(ed);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for (int i = 0; i < G[u].size();i++){
            if(!mark1[G[u][i]]){
                mark1[G[u][i]]=true;
                q.push(G[u][i]);
            }
        }
    }
    memcpy(mark2, mark1, sizeof(mark1));
    for (int i = 1; i <= n;i++){
        if(!mark1[i]){
            for (int j = 0; j < G[i].size();j++){
                if(mark2[G[i][j]])
                    mark2[G[i][j]] = 0;
            }
        }
    }
    q.push(ed);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for (int i = 0; i < G[u].size();i++){
            if(mark2[G[u][i]]){
                q.push(G[u][i]);
                mark2[G[u][i]] = 0;
                ans[G[u][i]] = ans[u] + 1;
            }
        }
    }
    if(ans[st]==0)
        cout << -1;
    else
        cout << ans[st];
    return 0;
}