#include <iostream>
using namespace std;
const int maxn=100000;
struct BIT{
	int C[maxn];
	int n;
	void init(){
		for (int i=0;i<maxn;i++){
			C[i]=0;
		}
	}
	int lowbit(int x){
		return x&-x;
	}
	void add(int x,int a){
		while (x<=n){
			C[x]+=a;
			x+=lowbit(x);
		}
	}
	int sum(int x){
		int ret=0;
		while (x>0){
			ret+=C[x];
			x-=lowbit(x);
		}
		return ret;
	}
};
int main(){
	int n,m;
	BIT st;
	st.init();
	cin>>n>>m;
	st.n=n;
	for (int i=1;i<=n;i++){
		int a;
		cin>>a;
		st.add(i,a);
	}
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if (a==1){
			st.add(b,c);
		}else {
			cout<<st.sum(c)-st.sum(b-1)<<endl;
		}
	}
}
