#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
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
const int maxn = 100005;
LL a[maxn],fib[maxn];
int n;
int cnt;
set<int> s;
bool check(int r){
    bool ok = true;
    for(int i=1;i<=cnt;i++){
        if(fib[i]-a[r]<0) continue;
        if(s.count(fib[i]-a[r])){
            ok=false;
            break;
        }
    }
    return ok;
}
int main(){
    freopen("f.in","r",stdin);
    freopen("f.out", "w", stdout);
    LL ans = 1;
    fib[1]=1;
    for (cnt = 2;;cnt++){
        fib[cnt] = fib[cnt - 1] + fib[cnt - 2];
        if(fib[cnt]>2e9)
            break;
    }
    read(n);
    for (int i = 1; i <= n;i++)
        read(a[i]);
    s.insert(a[1]);
    for (int i = 2; i <= n;i++){
        if(check(i)){
            s.insert(a[i]);
        }else{
            s.clear();
            ans++;
            s.insert(a[i]);
        }
    }
    cout << ans;
}