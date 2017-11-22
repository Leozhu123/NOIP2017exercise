#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

//int bi_find(int *a,int l,int r,int s){
//	if (l==r && a[l]!=s){
//		return 0;
//	}
//	
//	int mid=(l+r)/2;
//	if (a[mid]==s){
//		return mid;
//	}
//	if (a[mid]<s){
//		return bi_find(a,mid+1,r,s);
//	} else {
//		return bi_find(a,l,mid-1,s);
//	}
////	std::cout<<1<<std::endl;
//}
bool com(int a,int b){
	return a<b?true:false;
}
using namespace std;
int main(){
	int a[100000];
	int n,num_q,cnt=0;
	while (scanf("%d%d",&n,&num_q)){
		printf("CASE#%d:\n",++cnt);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,com);
		for(int i=0;i<num_q;i++){
			int tmp,v233;
			scanf("%d",&tmp);
			v233=lower_bound(a,a+n,tmp,com)-a;
			if (a[v233]==tmp){
			//	while (a[v233-1]==tmp) v233--;
				printf("%d found at %d\n",tmp,v233+1);
			} else printf("%d not found\n",tmp);
		}
	}
}
