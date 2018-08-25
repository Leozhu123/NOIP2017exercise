#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=300005;
int a[maxn], b[maxn];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1);
    int ans=0;
    ans=max(ans,b[1]-a[2]);
    ans=max(ans,b[2]-a[1]);
    cout << ans;
}