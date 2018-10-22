#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    char ch;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cin >> ch;
        int x = ch - '0';
        if(x==8)
            cnt++;
    }
    cout << min(cnt, n / 11);
}