#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int t=n;
	t-=5;
	int cnt=0;
	while(t>0){
		t-=4;
		cnt++;
	}
	cnt++;
	for(int i=1;i<=cnt;i++){
		cout<<5;
	}
	cout<<endl;
	for(int i=1;i<=cnt-1;i++){
		cout<<4;
	}
	cout<<5;
}
