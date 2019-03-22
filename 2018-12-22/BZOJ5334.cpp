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
int a[100005];

int main(){
	int T;
	read(T);
	for(int i=1;i<=T;i++){
		LL q,mod;
		LL x=1;
		read(q,mod);
		for(int i=1;i<=q;i++){
			int opt,m;
			read(opt,m);
			if(opt==1){
				x*=m;
				x%=mod;
				printf("%lld\n",x);
			}else{
				
			}
		}
	}
}