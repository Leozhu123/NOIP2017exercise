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
#define LL long long
#define LD long double
#define P pair<int,int>
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
const int maxn=4005;
vector<int> G[maxn];
bool mark[maxn];
int S[maxn];
int c;
int n,m;
int T[maxn][2];
bool dfs(int x){
	if(mark[x^1]) return false;
	if(mark[x]) return true;
	mark[x]=true;
	S[c++]=x;
	for(int i=0;i<G[x].size();i++)
		if(!dfs(G[x][i])) return false;
	return true;
}
void add(int x,int a,int y,int b){
	x=x*2+a;
	y=y*2+b;
	G[x^1].push_back(y);
	G[y^1].push_back(x);
}
bool solve(){
	for(int i=0;i<n*2;i+=2){
		if(!mark[i] && !mark[i+1]){
			c=0;
			if(!dfs(i)){
				while(c>0) mark[S[--c]]=0;
				if(!dfs(i+1)) return false;
			}
		}
	}
	return true;
}
int init(){
	for(int i=0;i<n*2;i++) G[i].clear();
	memset(mark,0,sizeof(mark));
}
bool check(int x){
	init();
	for(int i=0;i<n;i++)
		for(int a=0;a<2;a++)
			for(int j=i+1;j<n;j++)
				for(int b=0;b<2;b++)
					if(abs(T[i][a]-T[j][b])<x) add(i,a^1,j,b^1);
	return solve();
}
int main(){
	while(scanf("%d",&n)==1){
		int l=0,r=0;
		for(int i=0;i<n;i++)
			for(int a=0;a<2;a++){
				read(T[i][a]);
				r=max(r,T[i][a]);
			}
		while(l<r){
			int mid=l+(r-l+1)/2;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
}






