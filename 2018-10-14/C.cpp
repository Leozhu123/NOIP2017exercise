#include <iostream>
using namespace std;
int a[200];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        a[ch]++;
    }
    for (int i = 0; i < 200;i++){
        for(int j=0;j<a[i];j++){
            cout << (char)(i);
        }
    }
}