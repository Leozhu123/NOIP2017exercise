#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool ok=true;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==1)
            ok = false;
    }
    cout << (ok ? "EASY" : "HARD");
}
