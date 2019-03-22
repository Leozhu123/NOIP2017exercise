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
const int maxn=2000005;
vector<int> G[maxn];
bool mark[maxn];
int S[maxn];
int c;
int n,m;
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
 
int main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		int x,y,a,b;
		read(x,a,y,b);
		add(x-1,a,y-1,b);
	}
	if(!solve()){
		puts("IMPOSSIBLE");
		return 0;
	}else{
		puts("POSSIBLE");
		for(int i=0;i<2*n;i+=2){
			if(mark[i]) printf("0 ");
			else printf("1 ");
		}
	}
}






