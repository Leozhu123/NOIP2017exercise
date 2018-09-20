#include <iostream>
using namespace std;
using LL = long long;
const LL mod = 10007;
LL fast_pow(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
        ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
LL c=1,d=1;
int main(){
    LL a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    for(int i=n+1;i<=k;i++) c=(c*i)%mod;
    for(int i=1;i<=k-n;i++) d=(d*i)%mod;
    d=fast_pow(d,mod-2);
    c=(c*d)%mod;
    cout << (((c%mod * fast_pow(a, n)%mod)%mod * fast_pow(b, m)%mod)%mod)%mod;
}
