#include <iostream>
using namespace std;
const int maxlog = 63;
#define LL long long
LL a[64];
void ins(LL x){
    for (int i = maxlog;i>=0;i--){
        if(x&((LL)(1)<<i)){
            if(!a[i]){
                a[i]=x;
               // cout << a[i];
                return;
            }else{
                x ^= a[i];
            }
        }
    }
}
LL qmax(){
    LL res=0;
    for(int i=maxlog;i>=0;i--){
        if((res^a[i])>res)
            res ^= a[i];
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        LL x;
        cin>>x;
        ins(x);
    }
    cout << qmax();
}