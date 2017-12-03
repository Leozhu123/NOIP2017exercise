#include <iostream>
#include <queue>
#include <cstdio>
int map[105][105];
struct point{
	int x,y,de;
};	
int add_x[4]={0,0,1,-1};
int add_y[4]={1,-1,0,0};
using namespace std;
int main(){
	int n;
	cin>>n;
	queue<point> q;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
		
			char ch;
			cin>>ch;
			if (ch=='.') map[i][j]=1;
		    if (ch=='@') {
				map[i][j]=-1;
				point tmp;
				tmp.x=i;
				tmp.y=j;
				tmp.de=1;
				q.push(tmp);
			}	
	}
	int m;
	cin>>m;
	while (!q.empty()){
		if (q.empty()) break;
		point tmp=q.front();
		q.pop();
		if (tmp.de>=m) continue;
		for (int i=0;i<4;i++){
			int nx=tmp.x+add_x[i];
			int ny=tmp.y+add_y[i];
			if (map[nx][ny]==1){
				point tmpp;
				tmpp.x=nx;
				tmpp.y=ny;
				tmpp.de=tmp.de+1;
				map[nx][ny]=-1;
				q.push(tmpp);
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (map[i][j]==-1) ans++;
		}
    cout<<ans;
}	
