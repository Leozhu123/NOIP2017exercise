#include <iostream>
using namespace std;
int n;
int a[105],sum[105];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch;
        cin >> ch;
        a[i] = ch - '0';
    }
    bool ok=false;
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    int tar;
    int last;
    int pos;
    for(int i=1;i<=n;i++){
        tar = sum[i];
        pos = i + 1;
        last = i;
        while(pos<=n){
            while(a[pos]==0 && pos<=n)
                pos++;
            if(sum[pos]-sum[last]>tar)
                break;
            if(sum[pos]-sum[last]==tar){
                last = pos;
                while(a[pos+1]==0 && pos<n)
                    pos++;
                if(pos>=n)
                    ok = true;
            }
            pos++;
        }
    }
    if(ok)
        cout << "YES";
    else
        cout << "NO";
}