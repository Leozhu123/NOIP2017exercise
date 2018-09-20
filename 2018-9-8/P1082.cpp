#include <iostream>
using namespace std;
using LL = long long;
LL exgcd(LL a,LL b,LL &x,LL &y){
	int d=a;
	if(b!=0){
		d=exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;
		y=0;
	}
	return d;
}
LL c=1,d=1;
int main(){
    LL a, b,x,y;
    cin >> a >> b;
    exgcd(a,b,x,y);
    cout<<(x+b)%b;
}
