#include <iostream>
using namespace std;
const long long maxn = (1 << 10);
long long dp[10][100][maxn];
long long cntking(long long x){
    long long ans = 0;
    while(x){
        if(x&1) ans++;
        x >>= 1;
    }
    return ans;
}
int main(){
    long long n,kk;
    cin >> n >> kk;
    for (long long i = 0; i < (1 << n);i++)
        if((i&(i<<1))==0 && (i&(i>>1))==0)
            dp[1][cntking(i)][i] = 1;
    for (long long i = 2;i<=n;i++)
        for (long long j = 0; j < (1 << n);j++)
            for (long long k = 0;k<( 1 << n );k++)
                if((k&j)==0 && (j&(j<<1))==0 && (j&(j>>1))==0 )
                    if((j&(k<<1))==0 && (j&(k>>1))==0 )
                        for (long long a = 0 ; a <= kk;a++)
                            dp[i][a+cntking(j)][j] += dp[i - 1][a][k];
                    
    long long ans=0;
    for (long long i = 0; i < (1 << n);i++){
        ans += dp[n][kk][i];
    }
    cout << ans;
}