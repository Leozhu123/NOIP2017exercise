#include <iostream>
#include <utility>
#include <algorithm>
#define P pair<int,int>
using namespace std;
int n;
int a[100005],c[100005];
P b[100005];
bool cmp(P a,P b){
    return a.first < b.first;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i] = P(a[i], i);
    }
    sort(b,b+n);
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        bool ok = false;
        int index = lower_bound(b, b + n, b[i],cmp) - b;
       // cout << index << endl;
        for (int j = index;j>=0;j--){
            if(b[j].first<b[i].first && c[b[j].second]==0){
                c[b[j].second] = b[i].first;
                ok = true;
                ans++;
                break;
            }
        }
        if(!ok)
            break;
    }
    c[b[n - 1].second] = b[0].first;
   // cout << endl;
    cout << ans;
}