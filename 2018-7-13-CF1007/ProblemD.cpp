#include <iostream>
using namespace std;
int main(){
    int n;
    int t;
    cin>>t;
    for (int ca = 0; ca < t;ca++){
        int a,b,c;
        cin>>a>>b>>c;
        long long cc = a * b * c;
        int count=0;
        for (int i = 1; i <= cc;i++){
            if(cc % i)
                count++;
        }
        count *= 3;
        long long ans = count * (count - 1) * (count - 2) / 6;
        cout << ans << endl;
    }
}