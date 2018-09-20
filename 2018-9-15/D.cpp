#include <iostream>
using namespace std;
int calc(int x){
    int ans = 0;
    while(x){
        if(x&1) ans++;
        x >>= 1;
    }
    return ans;
}
int a[5005];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i = 1;i<=m;i++){
        int ans=0;
        int l,r;
        cin>>l>>r;
        for (int j = l; j <= r;j++){
            for (int p = j + 1; p <= r;p++){
                if(calc(a[j]^a[p])==k)
                    ans++;
            }
        }
        cout << ans << endl;
    }
}