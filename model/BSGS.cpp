#include <iostream>
#include <cctype>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#define LL long long
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;
    int f=0,ch=getchar();
    while(!isdigit(ch)) f|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    if(f) x=-x;
}
LL exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1,y=0;
		return a;
	}else{
		int d=exgcd(b,a%b,y,x);
		y-=(a/b)*x;
		return d;
	}
}
map<LL,LL> m;
LL BSGS(LL A,LL B,LL C){
	m.clear();
	if (C==1) if (!B) return A!=1; else return -1;
    if (B==1) if (A) return 0; else return -1;
    if (A%C==0) if (!B) return 1; else return -1; 
	int sqrtn=(int)sqrt(C)+1;
	LL base=1;
	for(int i=0;i<sqrtn;i++){
		m[base]=i;
		base=base*A%C;
	}
	LL D=1;
	for(int i=0;i<=sqrtn;i++){
		LL x,y,r;
		r=exgcd(D,C,x,y);
		x=((LL)x*B%C+C)%C;
		if(m.count(x)) return i*sqrtn+m[x];
		D=(D*base)%C;
	}
	return -1;
}
int main(){
	LL A,B,C;
	while(~scanf("%lld%lld%lld",&C,&A,&B)){
		LL ans=BSGS(A,B,C);
		if(ans==-1)puts("no solution");
		else cout<<ans<<endl;
	}
}
