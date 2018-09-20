#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
const long long maxn = 500005;
long long bit[maxn];
long long n;
inline long long lowbit(long long x){
    return x & -x;
}
void add(long long x){
    for (; x <= n;x+=lowbit(x)){
        bit[x] += 1;
    }
}
long long sum(long long x){
    long long ans = 0;
    for (; x > 0;x-=lowbit(x)){
        ans += bit[x];
    }
    return ans;
}
long long a[maxn];
long long b[maxn];
bool cmp(const long long &l,const long long &r){
	return b[l]<b[r];
}
int main(){
    cin>>n;
    for (long long i = 1;i<=n;i++){
        cin>>b[i];
        a[i]=i;
    }
    sort(a + 1, a + n + 1,cmp);
    long long ans = 0;
    for (long long i = 1; i <= n;i++){
        add(a[i]);
        ans += i-sum(a[i]);
    }
    cout << ans;
}
