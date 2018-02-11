#include<iostream>
#include<cstring>
using namespace std;
struct coordinate{
	int x,y;
};
coordinate road[10005][10005];
int a[10005],price[10005],time[10005];

int main(){
	int t,m;
	memset(price,0,sizeof(price));
	memset(time,0,sizeof(time));
	cin>>m>>t;
	for (int i=1;i<=m;i++) cin>>price[i];
	for (int i=1;i<=m;i++) cin>>time[i];
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=t;j++)
	  {
	  	 if (time[i]<=j) a[j]=max(a[j],a[j-time[i]]+price[i]);
	  }
	cout<<a[t];
}
