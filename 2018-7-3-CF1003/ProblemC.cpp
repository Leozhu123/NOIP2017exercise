#include <iostream>
#include <iomanip>
using namespace std;
double dp[5005][5005];
long double ans = 0;
int main(){
    int n,tk;
    cin >> n>>tk;
    for (int i=1;i<=n;i++){
        cin >> dp[i][1];
    }
    for (int i=1;i<=n;i++){
        for (int k = 1;i-k>=-1;k++){
            dp[i][k] = dp[i - 1][k - 1]  + dp[i][1];
            if(k>=tk && ((long double)dp[i][k]/k)>ans)
                ans = (long double)dp[i][k]/k;
        }
    }
    cout <<setprecision(10)<<ans;
}