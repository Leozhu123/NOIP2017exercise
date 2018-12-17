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
const int maxn=100005;
int ch[maxn][2],key[maxn],s[maxn],cnt[maxn];
int tot=0;
void update(int x){
	s[x]=s[ch[x][0]]+s[ch[x][1]]+cnt[x];
}
void route(int &x,int o){
	int y=ch[x][o^1];
	ch[x][o^1]=ch[y][o];
	ch[y][o]=x;
	update(x);
	update(y);
	x=y;
}
void maintain(int x,bool f){
	if(!f){
		if(s[ch[ch[x][0]][0]]>s[ch[x][1]]) route(x,1);
		else if(s[ch[ch[x][0]][1]]>s[ch[x][1]]) route(ch[x][0],0),route(x,1);
		else return;
	}else{
		if(s[ch[ch[x][1]][1]]>s[ch[x][0]]) route(x,0);
		else if(s[ch[ch[x][1]][0]]>ch[x][0]) route(ch[x][1],1),route(x,0);
		else return;
	}
	maintain(ch[x][0],false);
	maintain(ch[x][1],true);
	maintain(x,false);
	maintain(x,true);
}
void insert(int &x,int a){
	if(x==0) {
		x=++tot,key[tot]=a;
		return;
	}
	if(key[x]==a) {
		cnt[x]++;
		return;
	}
	if(key[x]>a) insert(ch[x][0],a);
	else insert(ch[x][1],a);
	update(x);
	maintain(x,a>key[x]);
}







