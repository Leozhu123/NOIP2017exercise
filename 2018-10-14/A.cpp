#include <iostream>
#include <algorithm>
using namespace std;
int a[4];
int main(){
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a + 3);
    if(a[0]+a[1]>a[2]) cout<<"0";
    else{
        cout << (a[2] + 1 - a[0] - a[1]);
    }
}