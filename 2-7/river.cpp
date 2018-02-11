#include <iostream>
#include <cstdio>
using namespace std;
const int INF = (1 << 30) - 1;
int dp[100], num[100], s, t, l,n;

int main(){
    cin >> l;
    cin >> s >> t >> n;
    for (int i = 0; i < n;i++){
        cin >> num[i];
        dp[i] = INF;
    }
    dp[0] = 1;
    for (int i = 1; i < n;i++){
        int &min_d = dp[i];
        min_d=dp[i - 1] + 1;
        for (int j = i; j >= 0;j--){
            if (num[i]-num [j]>t)
                break;
            if (num[i]-num[j]>=s)
                min_d = min(min_d, dp[j]+1);
        }
    }
    cout << dp[n-1] + 1;
}