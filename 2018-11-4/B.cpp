#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=305;
int h[maxn];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)   
        cin>>h[i];
    h[0] = 0;
    sort(h,h+n+1);
    int ans = 0;
    int l = 0, r = n;
    for(int i=1;i<=n;i++){
        ans += (h[r] - h[l]) * (h[r] - h[l]);
        if(i%2==1){
            l++;
        }else{
            r--;
        }
    }
    cout << ans;
}