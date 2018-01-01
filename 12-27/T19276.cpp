#include <iostream>
#include <cstdio>
#include <algorithm>
const int maxn=10005;
int ans[maxn];
int n,m,num[maxn];
int main(){
  freopen("gongdao1.in","r",stdin); 
  scanf("%d%d",&m,&n);
  for (int i=0;i<m;i++) scanf("%d",&num[i]);
  int L=0,R=m-1,pos=0;
  int M=L+(R-L+1)/2;
  while (L<R && pos<m){
    M=L+(R-L+1)/2;
    int sum=0;
    for (int i=0;i<n;i++){
      sum=0;
      while (sum<=M && pos<m) sum+=num[pos++];
    }
    if (pos>=M) L=M+1; else R=M;
  }

  pos=0;
  for (int i=0;i<n;i++){
    int sum=0;
    while (sum<=L) sum+=num[pos++];
    ans[i]=sum;
  }
  std::sort(ans,ans+n);
  printf("%d\n",ans[n-1]-ans[0]);
  for (int i=0;i<n;i++) printf("%d ",ans[i]);
}  
