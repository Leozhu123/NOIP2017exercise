#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 3005;
const int inf = (1 << 30) - 1;
int n,m;
int val[maxn];
int dp[maxn][maxn];
struct Edge{
    int u,v,w;
    Edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<Edge> G[maxn];
int dfs(int u){
    if(u>n-m){
        dp[u][1]=val[u];
        return 1;
    }
    int sum=0;
    for(int i=0;i<G[u].size();i++){
        Edge &e=G[u][i];
        int t=dfs(e.v);
        sum+=t;
        for (int j = sum; j > 0;j--){
            for (int k = 1; k <= t;k++){
                if(j-k>=0){
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[e.v][k] - e.w);
                }
            }
        }
    }
    return sum;
}
int main(){
    cin>>n>>m;
    for (int i = 1;i<=n-m;i++){
        int t;
        cin>>t;
        for(int j=0;j<t;j++){
            int v,w;
            cin>>v>>w;
            G[i].push_back(Edge(i, v, w));
        }
    }
    for (int i = n - m + 1; i <= n;i++){
        cin >> val[i];
    }
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= n;j++){
            dp[i][j] = -inf;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = 0;
    }
    dfs(1);
   // for (int i = 1;i<=n;i++){
   //     cout << dp[1][i] << " ";
   // }
    //cout << endl;
    for (int i = n; i >= 1; i--)
    {
        if (dp[1][i] >= 0)
        {
            cout << i;
            return 0;
        }
        }
}