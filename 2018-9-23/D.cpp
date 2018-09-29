#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
LL gcd(LL a,LL b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    bool isEven = (k % 2) == 0;
    LL p = n * m;
    if(isEven)
        k /= 2;
    if(p%k!=0){
        puts("NO");
        return 0;
    }
    LL x = gcd(n, k);
    k /= x;
    LL a = n / x;
    x = gcd(m, k);
    k /= x;
    LL b=m/x;
    if(!isEven){
        if(a<n)
            a += a;
        else{
            b += b;
        }
    }
    puts("YES");
    puts("0 0");
    cout<<0<<" "<<b<<endl;
    cout << a << " " << 0 << endl;
}