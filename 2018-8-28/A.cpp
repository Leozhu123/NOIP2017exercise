#include <iostream>
using namespace std;

char a[200][200];
int n,m;
int x1,y1,x2,y2,x3,y3,x4,y4;
int main(){
    cin>>n>>m;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            a[i][j]='W';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='B' && a[i-1][j]=='W' && a[i][j-1] == 'W') x1=i,y1=j;
            if(a[i][j]=='B' && a[i+1][j]=='W' && a[i][j-1] == 'W') x2=i,y2=j;
            if(a[i][j]=='B' && a[i-1][j]=='W' && a[i][j+1] == 'W') x3=i,y3=j;
            if(a[i][j]=='B' && a[i+1][j]=='W' && a[i][j+1] == 'W') x4=i,y4=j;
        }
    }
    cout<<(x1+x2)/2<<" "<<(y1+y3)/2;
}
