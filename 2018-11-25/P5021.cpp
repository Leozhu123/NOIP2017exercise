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
const int maxn = 50005;
struct Edge{
	int v,w;
	Edge(int v,int w):v(v),w(w){}
};
vector<Edge> G[maxn];
multiset<int> s[maxn];
int n,m;
int ans=0;
int dfs(int x,int f,int lim){
	s[x].clear();
	int val=0;
	for(int i=0;i<G[x].size();i++){
		Edge &e=G[x][i];
		if(e.v==f) continue;
		val=dfs(e.v,x,lim)+e.w;
		if(val>=lim) ans++;
		else s[x].insert(val);	
	}
	int maxd=0;
	while(!s[x].empty()){
		if(s[x].size()==1)
			return max(maxd,*s[x].begin());
		multiset<int>::iterator it=s[x].lower_bound(lim-*s[x].begin());
		if(it==s[x].begin() && s[x].count(*it)==1) ++it;
		if(it==s[x].end()){
			maxd=max(maxd,*s[x].begin());
            s[x].erase(s[x].find(*s[x].begin()));
		}
		else{
			ans++;
			s[x].erase(s[x].find(*it));
            s[x].erase(s[x].find(*s[x].begin()));
		}
	}
	return maxd;
}
bool check(int x){
	ans=0;
	dfs(1,0,x);
	return ans>=m;
}
int main(){
	int l=0,r=0;
	read(n,m);
	for(int i=1;i<=n-1;i++){
		int a,b,l;
		read(a,b,l);
		G[a].push_back(Edge(b,l));
		G[b].push_back(Edge(a,l));
		r+=l;
	}
	while(l+5<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(int i=r;i>=l;i--){
		if(check(i)){
			cout<<i;
			return 0;
		}
	}
}






