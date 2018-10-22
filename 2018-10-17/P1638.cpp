#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 1000005;
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
int n,m;
int a[maxn];
int cnt[maxn];
int cntt = 0;
int ans = INT_MAX;
int ansl = 0, ansr = 0;
int main(){
    read(n,m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    int l = 1, r = 1;
    cnt[a[1]]++;
    cntt++;
    while(r<=n){
        while(cntt<m && r<=n){
            r++;
            cnt[a[r]]++;
            if(cnt[a[r]]==1)
                cntt++;
        }
        if(cntt<m)
            break;
        if(r-l+1<ans){
            ans = r-l+1;
            ansl = l;
            ansr = r;
        }
        cnt[a[l]]--;
        if(cnt[a[l]]==0)
            cntt--;
        l++;
    }
    printf("%d %d", ansl, ansr);
}