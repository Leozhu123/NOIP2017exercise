#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=100005;
int a[maxn];
int Stable[maxn][16];
struct ST{
	void init(int a[],int n){
		for (int i=1;i<=n;i++){
			Stable[i][0]=a[i];
		}
		for (int i=1;(1<<i)<=n;i++)
			for (int j=0;j+(1<<i)-1<=n;j++){
				Stable[j][i]=max(Stable[j][i-1],Stable[j+(1<<(i-1))][i-1]);
			}
	}
	int search(int L,int R){
		int k=0;
		while ((1<<(k+1))<=R-L+1) k++;
		return max(Stable[L][k],Stable[R-(1<<k)+1][k]);
	}
};
int main(){
	ST st;
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	st.init(a,n);
	for (int i=0;i<m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",st.search(l,r));
	}
}
