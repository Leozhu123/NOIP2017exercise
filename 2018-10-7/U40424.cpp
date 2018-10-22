#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
const int maxn=1000005;
const int p = 19260817;
LL a[maxn];
LL fast_pow(LL a,LL x,LL k){
    LL now=a;
    LL ans=1;
    while(x){
        if(x&1) ans=(ans%k * now %k)%k;
        now=(now%k * now%k)%k;
        x>>=1;
    }
    return ans;
}
int main(){
    int T;
    a[0] = 1;
    for (int i = 1; i < maxn;i++){
        a[i] = (a[i - 1] * i) % p;
    }
    cin>>T;
    while(T--){
        int x;
        cin>>x;
        cout << fast_pow(a[x], 1<<(x-1), p) << endl;
    }
}