#include <iostream>
using namespace std;
int n;
int a[200005];
int x,f;
int main(){
    cin>>n;
    for (int i = 1; i <= n;i++){
        cin>>a[i];
    }
    cin>>x>>f;
    long long ans=0;
    for(int i=1;i<=n;i++){
        a[i]+=f;
        ans += ((a[i]-1) / (f + x)) * f;
    }
    cout << ans;
}