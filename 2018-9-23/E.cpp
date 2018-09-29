#include <iostream>
#define LL long long
using namespace std;
const int maxn=300005;
LL a[maxn],b[maxn],c[maxn];
LL lowbit(LL x){
    return x & -x;
}
int count(LL x){
    int ans=0;
    while(x){
        ans++;
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        LL x;
        cin>>x;
        int cnt = count(x);
        for(int i=1;i<=cnt;i++){
            a[i] <<= 1;
            a[i] |= 1;
        }
    }
    for(int i=1;i<=n;i++){
        a[i] = a[i - 1] ^ a[i];
        int cnt = count(x);
        for(int i=1;i<=cnt;i++){
            a[i] <<= 1;
            a[i] |= 1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]%2==0)
            b[i]++;
        else
            c[i]++;
    }
    for (int i = 1; i <= n;i++){
        b[i] = b[i-1] + b[i];
        c[i] = c[i - 1] + c[i];
    }
    LL ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i-1]%2==0){
            ans += b[n] - b[i];
        }else{
            ans += c[n] - c[i];
        }
    }
    cout << ans;
}