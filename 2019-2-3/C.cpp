#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#define LL long long
#define LD long double
#define P pair<int,int>
using namespace std;
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
const int maxn = 1e5 + 5;
map<int, LL> cnt;
int n, k, A,B;
LL calc(int l,int r){
    auto it1=cnt.lower_bound(l);
    auto it2=cnt.upper_bound(r);
    it1--;
    it2--;
    return it2->second - it1->second;
}
LL solve(int l,int r){ 
    if(calc(l,r)==0) return A;
    if(l==r)
        return !cnt.count(l) || cnt[l] == 0 ? A : B * calc(l,l);
    int mid = (l + r) >> 1;
    return min((LL)calc(l, r) * B * (r - l + 1), (LL)solve(l, mid) + solve(mid + 1, r));
}
int main(){
    read(n, k, A,B);
    cnt[0] = 0;
    for (int i = 1; i <= k;i++){
        int tmp;
        read(tmp);
        cnt[tmp]++;
    }
    for (auto it = cnt.begin(); it != cnt.end();it++){
        auto prv=it;
        prv--;
        it->second += prv->second;
    }
    cout << solve(1, (1 << n));
}