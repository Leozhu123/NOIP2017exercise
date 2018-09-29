#include <iostream>
using namespace std;
const int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[2005];
int main(){
    int n;
    a[0] = 6;
    cin>>n;
    for(int i=1;i<=2000;i++){
        int j=i;
        while(j>=1){
            a[i]+=c[j%10];
            j /= 10;
        }
    }
    int ans = 0;
    for (int i = 0;i<=1000;i++){
        for (int j = 0; j <= 1000;j++){
            if(a[i]+a[j]+a[i+j]+4==n)
                ans++;
        }
    }
    cout << ans;
}