#include <iostream>
#include <algorithm>
using namespace std;
int dp[505][505],num[2][505],ans[505],pos,dp2[505],p[505];
void print_ans(int x){
  if (x==-1) return;
  if (x==0) {
  	cout<<ans[x]<<' ';
  	return;
  }
  print_ans(p[x]);
  cout<<ans[x]<<' ';
}  
int main(){
  int m;
  cin>>m;
  dp2[0]=1;
  for (int i=1;i<=m;i++) cin>>num[0][i],p[i]=-1,dp2[i]=1;
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>num[1][i];
  for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++){
      if (num[0][i]==num[1][j] ) {
        dp[i][j]=dp[i-1][j-1]+1;
        ans[pos++]=num[0][i];
      }  
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
    }   
  for (int i=1;i<=pos;i++){
    for (int j=0;j<i;j++){
      if (dp2[j]+1>dp2[i] && ans[i]>ans[j]) dp2[i]=dp2[j]+1,p[i]=j;
    }
  }
  int t=0,ma=0;
  for (int i=0;i<=pos;i++)
    if (dp2[i]>ma) ma=dp2[i],t=i;
  cout<<ma<<endl;
  print_ans(t);
}
