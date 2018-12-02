#include <iostream>
using namespace std;
int m;
int main(){
    cin>>m;
    int f0 = 1, f1 = 1;
    int n = 1;
    while(!(f0%m==0 && f1%m==1)){
        int tmp=f0+f1;
        f0=f1;
        f1 = tmp % m;
        n++;
    }
    cout << n;
}