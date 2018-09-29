#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct node{
    int l,r;
    bool operator <(const node &rr) const{
        if(r!=rr.r) 
            return r<rr.r;
        else
            return l < rr.l;
    }
};
node t[200005];
int ans=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        t[i].l = a - b;
        t[i].r = a + b;
    }
    sort(t+1,t+n+1);
    int r = -(1 << 30);
    for(int i=1;i<=n;i++){
        if(t[i].l>=r){
            ans++;
            r = t[i].r;
        }
    }
    cout << ans;
}