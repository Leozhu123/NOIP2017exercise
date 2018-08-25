#include <iostream>
#include <algorithm>
using namespace std;
const long long maxn = 200005;
long long a[maxn];
int main(){
    long long n;
    cin>>n;
    for (long long i = 1;i<=n;i++){
        cin>>a[i];
    }
    long long ans = 1;
    long long cnt = 1;
    for (long long i = 1;i<n;i++){
        if(a[i+1]<=a[i]*2)
            cnt++;
        else
            cnt = 1;
        ans = max(ans, cnt);
    }
    cout << ans;
}