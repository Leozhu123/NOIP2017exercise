#include <iostream>
#include <cstdio>
int map[105][105];	
int add_x[4]={0,0,1,-1};
int add_y[4]={1,-1,0,0};
using namespace std;
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
		
			char ch;
			cin>>ch;
			if (ch=='.') map[i][j]=1; 
		    else if (ch=='@') map[i][j]=-1;
		    else map[i][j]=0;
	}
	int m;
	cin>>m;
	for (int k=2;k<=m;k++){
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++){
				if (map[i][j]==-1){
					for (int p=0;p<4;p++){
						int nx=i+add_x[p];
						int ny=j+add_y[p];
						if (map[nx][ny]==1) map[nx][ny]=-2;
					}
				}
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++){
			  if (map[i][j]==-2) map[i][j]=-1;	
			}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (map[i][j]==-1) ans++;
	}
    cout<<ans;
}	
