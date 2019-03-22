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
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
const int maxn = 2e5 + 5;
P a[maxn];
bool book[maxn];
LL ans = 0;
int main(){
    int n,m,k;
    read(n,m,k);
    for (int i = 1; i <= n;i++){
        read(a[i].first);
        a[i].second = i;
    }
    sort(a+1,a+n+1,greater<P >());
    LL ans = 0;
    for(int i=1;i<=m*k;i++){
        ans+=a[i].first;
        book[a[i].second] = 1;
    }
    cout<<ans<<endl;
    int cnt = 0;
    for (int i = 1; i < n;i++){
        if(book[i]) cnt++;
        if(cnt==m)
            cout << i << " ", cnt = 0;
    }
}