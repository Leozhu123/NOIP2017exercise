#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
#define P pair<int,int>
const int maxn = 1000005;
const int M = 99999997;
int bit[maxn];
int n;
inline int lowbit(int x){
    return x & -x;
}
void add(int x){
    for (; x <= n;x+=lowbit(x)){
        bit[x] += 1;
        bit[x]%=M;
    }
}
int sum(int x){
    if(x==0) return 0;
    int ans = 0;
    for (; x > 0;x-=lowbit(x)){
        ans += bit[x];
        ans%=M;
    }
    return ans;
}
P a[maxn], b[maxn];
int c[maxn];
int main(){
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n;i++){
        cin>>b[i].first;
        b[i].second = i;
    }
    sort(a + 1, a + n + 1);
    sort(b+1,b+n+1);
    for (int i = 1;i<=n;i++){
        c[a[i].second] = b[i].second;
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        add(c[i]);
        ans += i-sum(c[i]);
        ans %= M;
    }
    cout << ans;
}