#include <iostream>
#include <ctime>
#include <algorithm>
#define LL long long
using namespace std;
LL calc(LL x){
    LL ret=0;
    while(x>0){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int num[20];
int main(){
    LL n;
    cin>>n;
    LL nn = n;
    int pos = 0;
    while(n>0){
        num[pos++] = n % 10;
        n /= 10;
    }
    LL fir = num[pos - 1]/2;
    for (int i = 0; i < pos - 1;i++){
        fir = fir * 10 + 9;
    }
    cout << calc(fir)+(calc(nn-fir));
}