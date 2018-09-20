#include<iostream>
using namespace std;
const long long mod=1000000007;
long long f[201][201]={1},sum[201][201],n,m,ki;
char a[1001],b[201];
int main(){
    cin>>n>>m>>ki>>a>>b;
    for(int i=1;i<=n;i++)
      for(int j=m;j>=1;j--)
        for(int k=ki;k>=1;k--)
              f[j][k]=(f[j][k]+ (sum[j][k]= a[i-1]==b[j-1]? sum[j-1][k]+f[j-1][k-1] : 0))%mod;
    cout<<f[m][ki];
}
