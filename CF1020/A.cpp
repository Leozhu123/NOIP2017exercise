#include <algorithm>
#include <iostream>
using namespace std;
int abs(int a){
    return a > 0 ? a : -a;
}
int main(){
    int n,h,a,b,k;
    cin>>n>>h>>a>>b>>k;
    for(int i=1;i<=k;i++){
        int ta,fa,tb,fb;
        cin >> ta>> fa>> tb>> fb;
        int ans=abs(tb-ta);
        if(ta==tb) {
            cout<<abs(fa - fb)<<endl;
            continue;
        }
        if(a<=fa && fa<=b){
            ans += abs(fa - fb);
            cout << ans << endl;
            continue;
        }
        if(a<=fb && fb<=b){
            ans += abs(fa - fb);
            cout<<ans<<endl;
            continue;
        }
        if(fa<a){
            ans += abs(fa - a) + abs(fb - a);
            cout << ans << endl;
            continue;
        }
        if(fa>b){
            ans+=abs(fa-b)+abs(fb-b);
            cout<<ans<<endl;
            continue;
        }

    }
}