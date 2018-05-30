#include <iostream>
#include <cstdio>
#include <algorithm>
const int maxn=10000;
using namespace std;
int dp1[maxn],dp2[maxn],num[maxn];
int main(){
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    scanf("%d",&num[i]);
    dp1[i]=dp2[i]=1;
}
  for (int i=0;i<n;i++)
    for (int j=0;j<i;j++)
      if (num[j]<num[i]) dp1[i]=max(dp1[i],dp1[j]+1);
  for (int i=n-1;i>=0;i--)
    for (int j=n-1;j>i;j--)
      if (num[j]<num[i]) dp2[i]=max(dp2[i],dp2[j]+1);
  int ans=0;
  for (int i=0;i<n;i++)
    ans=max(ans,dp1[i]+dp2[i]-1);
  printf("%d",n-ans);
}
