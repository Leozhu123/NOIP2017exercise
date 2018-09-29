#include <iostream>
#include <cctype>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct Node{
	int x,y,w;
};
int n;
Node node[10005];
double pe(double nowx,double nowy){
	double sum=0;
	for(int i=1;i<=n;i++){
		double delx=nowx-node[i].x;
		double dely=nowy-node[i].y;
		sum+=(sqrt(delx*delx+dely*dely))*node[i].w;
	}
	return sum;
}
double xans,yans;
double ans=1e18+7,t;
const double delta=0.995;
void sa(){
	double xx=xans;
	double yy=yans;
	t=1926;
	while(t>1e-14){
		double xtmp=xans+(rand()*2-RAND_MAX)*t;
		double ytmp=yans+(rand()*2-RAND_MAX)*t;
		double newans=pe(xtmp,ytmp);
		double DE=newans-ans;
		if(DE<0){
			xx=xtmp;
			yy=ytmp;
			xans=xx;
			yans=yy;
			ans=newans;
		}else if(exp(-DE/t)*RAND_MAX>rand()){
			xx=xtmp;
			yy=ytmp;
		}
		t*=delta;
	}
}
int main(){
	cin>>n;
	srand(time(0));
	for(int i=1;i<=n;i++){
		cin>>node[i].x;
		cin>>node[i].y;
		cin>>node[i].w;
	}
	sa();
	sa();
	sa();
	printf("%.3lf %.3lf",xans,yans);
}
