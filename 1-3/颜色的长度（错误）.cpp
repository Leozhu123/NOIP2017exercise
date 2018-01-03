#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=5005,INF=100000;
char p[maxn],q[maxn];
bool app[26];
int sp[maxn],sq[maxn],ep[maxn],eq[maxn],cop[maxn],coq[maxn],dp[maxn][maxn];
inline int min(int a,int b){ return a<b?a:b;}
inline int max(int a,int b){ return a>b?a:b;}
int main(){
  scanf("%s%s",p+1,q+1);
  int n=strlen(p+1),m=strlen(q+1);
  for(int i = 1; i <= n; i++) p[i] -= 'A';
  for(int i = 1; i <= m; i++) q[i] -= 'A';
  for(int i = 0; i < 26; i++) { sp[i] = sq[i] = INF; ep[i] = eq[i] = 0; }
  for(int i = 1; i <= n; i++) {
    sp[p[i]] = min(sp[p[i]], i);  
    ep[p[i]] = i;
  }
  for(int i = 1; i <= m; i++) { 
    sq[q[i]] = min(sq[q[i]], i);
    eq[q[i]] = i;
  }
  for (int i=0;i<26;i++){
    if (sp[i]!=INF)
      for (int j=sp[i];j<=ep[i];j++)
        cop[j]++;
    if (sq[i]!=INF)
      for (int j=sq[i];j<=eq[i];j++)
        coq[j]++;
  }
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
      dp[i][j]=min(dp[i-1][j]+cop[i-1],dp[i][j-1]+coq[j-1]);
  cout<<dp[n][m];
}  
