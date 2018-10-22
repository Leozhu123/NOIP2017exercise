#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
const int p = 19260817;
bool t = true;
int n, m, ans, cnt, sum = 0;
LL A[103], key[1000003];
LL read(){
    LL sum=0,fg=1;
    char c=getchar();
    while(c < '0' || c > '9')
    {
        if(c=='-') fg=-1;
        c=getchar();
    }
    while(c >='0' && c <='9')
    {
        sum=((sum*10)+c-'0')%p;
        c=getchar();
    }
    return sum*fg;
}
bool calc(LL x){
    sum=0;
    for(int i=n;i>=1;i--){
        sum = ((A[i] + sum) * x) % p;
    }
    sum = (sum + A[0]) % p;
    return sum==0;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        A[i] = read();
    }
    for(int i=1;i<=m;i++){
        if(calc(i)){
            t = false;
            ans++;
            key[++cnt] = i;
        }
    }
    if(t){
        cout << ans << endl;
        return 0;
    }
    cout<<ans<<endl;
    for(int i=1;i<=cnt;i++){
        cout << key[i] << endl;
    }
}