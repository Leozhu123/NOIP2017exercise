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
#include <set>
#include <cstdlib>
#define P system("pause");
#define LL long long
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
vector<int> G[maxn];
bool vis[maxn];
int edge[maxn][2];
int ans[maxn];
int n,m;
namespace solve1{
	int cnt=0;
	void dfs(int x){
		ans[++cnt]=x;
		vis[x]=true;
		for(int i=0;i<G[x].size();i++){
			int v=G[x][i];
			if(!vis[v]) dfs(v);
		}
	}
	void solve(){
		memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        cnt=0;
        for (int i=1;i<=n;i++)
            sort(G[i].begin(),G[i].end());
        dfs(1);
        for (int i=1;i<=n;i++)
            printf("%d ",ans[i]);
	}
}
namespace solve2{
	int cnt=0;
	int res[maxn];
	bool comp()
    {
        for (int i=1;i<=n;i++)
            if (ans[i]!=res[i])
                return ans[i]>res[i];
        return false;
    }
    int del_u,del_v;

    bool check(int u,int v)
    {
        if ((u==del_u && v==del_v) || (u==del_v && v==del_u))
            return false;
        return true;
    }
    void dfs(int x){
    	res[++cnt]=x;
    	vis[x]=true;
    	for(int i=0;i<G[x].size();i++){
    		int v=G[x][i];
    		if(!vis[v] && check(x,v)) dfs(v);
		}
	}
	void solve()
    {
        memset(ans,0x3f,sizeof(ans));
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
            sort(G[i].begin(),G[i].end());
        for (int i=1;i<=m;i++)
        {
            cnt=0;
            memset(res,0,sizeof(res));
            memset(vis,0,sizeof(vis));
            del_u=edge[i][0];
            del_v=edge[i][1];
            dfs(1);
            if (comp() && cnt==n)
                memcpy(ans,res,sizeof(res));
        }
        for (int i=1;i<=n;i++)
            printf("%d ",ans[i]);
    }
}
int main(){
	read(n,m);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        read(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
        edge[i][0]=u;
        edge[i][1]=v;
    }
    if (m==n-1)
        solve1::solve();
    else
        solve2::solve();
    return 0;
}
