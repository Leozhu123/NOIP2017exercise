#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const double eps=1e-6;
using vec=vector<double>;
using mat=vector<vec>;
int abs(int a){
	return a>0?a:-a;
}
bool gouse(mat A,vec &b,int n){
	mat B(n,vec(n+1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			B[i][j]=A[i][j];
		}
		B[i][n]=b[i];
	}
	for(int i=0;i<n;i++){
		int idx=i;
		for(int j=i;j<n;j++){
			if(abs(B[j][i])>abs(B[idx][i])) idx=j;
		}
		swap(B[idx],B[i]);
		if(abs(B[i][i])<=eps) return 0;
		for(int j=i+1;j<=n;j++){
			B[i][j]/=B[i][i];
		}
		for(int j=0;j<n;j++){
			if(j==i) continue;
			for(int k=i+1;k<=n;k++){
				B[j][k]-=B[j][i]*B[i][k];
			}
		}
	}
	for(int i=0;i<n;i++){
		b[i]=B[i][n];
	}
	return 1;
}
int main(){
	int n;
	cin>>n;
	vec b(n);
	mat A(n,vec(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
		cin>>b[i];
	}
	if(gouse(A,b,n)){
		for(int i=0;i<n;i++){
			printf("%.2lf\n",b[i]);
		}
	}else{
		puts("No Solution");
	}
}
