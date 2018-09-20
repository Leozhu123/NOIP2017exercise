#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=5005,inf=(1<<31)-1;
int a[maxn],b[maxn];
int main(){
	int ans1=0,ans2=0;
	int l,n;
	cin>>l>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a[i]=min(l-t+1,t);
		b[i]=max(l-t+1,t);
	}
	for(int i=0;i<n;i++){
		ans1=max(ans1,a[i]);
		ans2=max(ans2,b[i]);
	}
	cout<<ans1<<" "<<ans2;
}
