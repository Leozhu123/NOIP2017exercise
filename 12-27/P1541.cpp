#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=(1<<31)-1,maxn=400;
int ans[maxn],score[maxn],nn[5];
int search(int x){
  int t=ans[x];
  for (int i=1;i<5;i++){
    if (nn[i]>0 && x-i>=0){
      nn[i]--;
      t=max(t,search(x-i)+score[x]);
	  nn[i]++;
    }
  }  
  ans[x]=t;
  return t;
}      
int main(){
  int n,m;
  for (int i=0;i<maxn;i++) ans[i]=-INF;
  scanf("%d%d",&n,&m);
  for (int i=0;i<n;i++) scanf("%d",&score[i]);
  for (int i=0;i<m;i++) {
    int t;
    scanf("%d",&t);
    nn[t]++;
  }
  ans[0]=score[0];
  printf("%d\n",search(n-1));
  for (int i=0;i<n;i++) printf("%d ",ans[i]); 
}  
