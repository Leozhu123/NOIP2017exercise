#include <iostream>
#include <cmath>
#define LL long long
using namespace std;
int count(LL x){
    int ans = 0;
    while(x){
        if(x&1) ans++;
        x >>= 1;
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        LL x;
        cin>>x;
        cout << ((LL)1 << (LL)count(x)) << endl;
    }
}