//by ciwomuli
//AK JSOI 2019
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
#include <sstream>
#define LL long long
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
const int maxn = 300;
int a[maxn];
int n;
int ans = 0;
int A[maxn], B[maxn];
bool test(){
    bool ok = true;
    for (int s = 1; s <= n;s++){
        int cnt1=0,cnt2=0;
        int l = s;
        while(!(l == 1 || a[l-1] > a[s])) l--;
        int r = s;
        while(!(r == n || a[r+1] >= a[s])) r++;
        cnt1 = s - l + 1;
        cnt2 = r - s + 1;
        if(abs(cnt1-cnt2) > 2) {
            ok=false;
            break;
        }
    }
    return ok;
}
void dfs(int x){
    if(x == 0) {
        if(test())
            ans++;
        return;
    }
    for (int i = A[x];i <= B[x];i++){
        a[x] = i;
        dfs(x - 1);
    }
}
int main(){
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    read(n);
    for(int i = 1;i <=n;i++){
        read(A[i],B[i]);
    }
    dfs(n);
    cout << ans;
}