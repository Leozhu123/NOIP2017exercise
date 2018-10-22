#include <iostream>
#include <climits>
#include <unordered_map>
#define LL long long
using namespace std;
const int base = 12;
const int inf = INT_MAX >> 2;
unordered_map<LL ,int > mp;
int a[12][12], b[12][12];
int num[12];
int n,m;
inline LL zip(){
    LL ret = 0;
    for(int i=1;i<=n;i++){
        ret = ret * base + num[i];
    }
    return ret;
}
inline void unzip(LL x){
    for(int i=n;i>=1;i--){
        num[i] = x % base;
        x /= base;
    }
}
int dfs(LL x,bool hand){
    auto pos = mp.find(x);
    if(pos!=mp.end()){
        return pos->second;
    }
    unzip(x);
    int ret = hand ? -inf : inf;
    for(int i=1;i<=n;i++){
        if(num[i]<num[i-1]){
            num[i]++;
            LL nxt = zip();
            if(hand)
                ret = max(ret, dfs(nxt, 0) + a[i][num[i]]);
            else
                ret = min(ret, dfs(nxt, 1) - b[i][num[i]]);
            num[i]--;
        }
    }
    mp[x]=ret;
    return ret;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= m;j++){
            cin >> b[i][j];
        }
    }
    for(int i=0;i<=n;i++)
        num[i] = m;
    LL last=zip();
    mp[last] = 0;
    cout << dfs(0, 1);
}