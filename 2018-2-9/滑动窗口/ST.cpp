#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=200005;
int a[maxn];
int Stablemax[maxn][16],Stablemin[maxn][16];
struct STmax{
	inline void init(int a[],int n){
		for (int i=1;i<=n;i++){
			Stablemax[i][0]=a[i];
		}
		for (int i=1;(1<<i)<=n;i++)
			for (int j=0;j+(1<<i)-1<=n;j++){
				Stablemax[j][i]=max(Stablemax[j][i-1],Stablemax[j+(1<<(i-1))][i-1]);
			}
	}
	inline int search(int L,int R){
		int k=0;
		while ((1<<(k+1))<=R-L+1) k++;
		return max(Stablemax[L][k],Stablemax[R-(1<<k)+1][k]);
	}
};
struct STmin{
	inline void init(int a[],int n){
		for (int i=1;i<=n;i++){
			Stablemin[i][0]=a[i];
		}
		for (int i=1;(1<<i)<=n;i++)
			for (int j=0;j+(1<<i)-1<=n;j++){
				Stablemin[j][i]=min(Stablemin[j][i-1],Stablemin[j+(1<<(i-1))][i-1]);
			}
	}
	inline int search(int L,int R){
		int k=0;
		while ((1<<(k+1))<=R-L+1) k++;
		return min(Stablemin[L][k],Stablemin[R-(1<<k)+1][k]);
	}
};
int main(){
	STmax stmax;
	STmin stmin;
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	stmax.init(a,n);
	stmin.init(a,n);
	for (int i=0;i<=n-k;i++){
		printf("%d ",stmin.search(i,i+k-1));
	}
	printf("\n");
	for (int i = 0; i <= n - k; i++)
	{
		printf("%d ",stmax.search(i,i+k-1));
	}
}
