#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(){
	int  n,t;
	long long da[200005];
	scanf("%ld%ld",&n,&t);
	for (int i=0;i<n;i++){
		 scanf("%ld",&da[i]);
	}
	int ans=0;
	for (int i=0;i<n-1;i++){
		if (da[i+1]-da[i]>t){
			ans+=t;
		} else if (da[i+1]-da[i]<=t){
			ans+=da[i+1]-da[i];
		}
	}
	ans+=t;
	printf("%d",ans);
}
