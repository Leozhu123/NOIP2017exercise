#include <iostream>
using namespace std;
const int M = 1e9;
bool state[1 << 12];
int n, m;
int dp[15][1 << 12];
int ma[15][15];
int f[15];
int main(){
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cin >> ma[i][j];
        }
    }
    for (int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            f[i] = (f[i] << 1) + ma[i][j];
        }
    }
    int maxstate=(1<<m);
    for(int i=0;i<maxstate;i++){
        state[i] = ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for (int j = 0; j < maxstate;j++){
            if(state[j] &&((j&f[i])==j)){
                for (int k = 0; k < maxstate;k++){
                    if((k&j)==0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<maxstate;i++){
        ans+=dp[n][i];
        ans %= M;
    }
    cout << ans << endl;
}