#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm> 
using namespace std;
const int maxn=21,INF=1<<30;
int n,x[maxn],y[maxn],z[maxn];
double d[maxn][maxn],dp[1<<21];
int main(){
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>x[i]>>y[i]>>z[i];
  }
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      if (i==j) d[i][j]=0;
      else d[i][j]=d[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
  printf("%02f\n",d[0][1]);    
  for (int S=0;S < (1<<n) ;S++){
    int i,j;
    dp[S]=INF;
    for (i=0;i<n;i++)
      if ( S& (1<<i) !=0) break;
    for (j=i+1;j<n;j++)
      if ( S & (1<<j) !=0) dp[S]=min(dp[S],d[i][j]+dp[S^(1<<i)^(1<<j)]);
  }
  printf("%02f",dp[(1<<n)-1]);
  cout<<dp[(1<<n)-1];
}  
