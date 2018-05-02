#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=600000;
int C[maxn];
struct BIT{
	int n;
	inline void init(){
		for (int i=0;i<maxn;i++){
			C[i]=0;
		}
	}
	inline int lowbit(int x){
		return x&-x;
	}
	inline void add(int x,int a){
		while (x<=n){
			C[x]+=a;
			x+=lowbit(x);
		}
	}
	inline int sum(int x){
		int ret=0;
		while (x>0){
			ret+=C[x];
			x-=lowbit(x);
		}
		return ret;
	}
};
int a[maxn];
int main(){
	int n,m;
	BIT st;
	st.init();
	scanf("%d%d",&n,&m);
	st.n=n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		st.add(i,a[i]-a[i-1]);
	}
	for (int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		if (a==1){
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			st.add(b,d);
			st.add(c+1,-d);
		}else {
			int b;
			scanf("%d",&b);
			cout<<st.sum(b)<<endl;
		}
	}
}
