#include <iostream>
#include <string>
using namespace std;
string t;
int main(){
    int n,k;
    cin >> n >> k;
    cin>>t;
    int cnt = -1;
    for (int i = 0; i < n-1;i++){
        bool ok = true;
     //   cout << i <<  endl;
        for (int j=0;j<=i;j++){
        //    cout << i << " " << j << endl;
            if(t[j]!=t[n-i-1+j]) {
             //   cout << i << " " << j << endl;
                ok=false;
                break;
            }
        }
        if(ok)
            cnt = i;
    }
  //  cout << cnt << endl;
    if(cnt==-1){
        for (int i = 0; i < k;i++){
            cout << t;
        }
        return 0;
    }
    cout << t;
    for (int i = 1; i < k;i++){
        for (int j = cnt+1; j < n;j++){
            cout << t[j];
        }
    }
}