#include <iostream>
#define LL long long
const int maxn = 2000005;
using namespace std;
LL n, m, S;
LL sum = 0;
LL Y = 0;
LL w[maxn], v[maxn];
LL pre_n[maxn], pre_v[maxn];
LL ll[maxn], rr[maxn];
bool check(LL x)
{
    Y = sum = 0;
    for (int i = 0;i<=n;i++){
        pre_n[i] = pre_v[i] = 0;
    }
    for (int i = 1; i <= n;i++){
        if(w[i]>=x)
            pre_n[i] = pre_n[i - 1] + 1, pre_v[i] = pre_v[i - 1] + v[i];
        else
            pre_n[i] = pre_n[i - 1], pre_v[i] = pre_v[i - 1];
    }
    for (int i = 1; i <= m;i++){
        Y += (pre_n[rr[i]] - pre_n[ll[i] - 1]) * (pre_v[rr[i]] - pre_v[ll[i] - 1]);
    }
    sum = llabs(Y - S);
    if(Y>S)
        return true;
    else
        return false;
}
LL mn, mx;
int main(){
    cin >> n >> m >> S;
    for (int i = 1; i <= n;i++){
        cin >> w[i] >> v[i];
        mx = max(mx, w[i]);
        mn = min(mn, w[i]);
    }
    for (int i = 1; i <= m;i++){
        cin >> ll[i] >> rr[i];
    }
    LL l = mn-1;
    LL r = mx+2;
    LL ans = INT64_MAX;
    while(l<=r){
        LL mid=(l+r)>>1;
        if(check(mid))
            l = mid+1;
        else
            r = mid-1;
        if(sum<ans)
            ans = sum;
    }
    cout << ans;
}