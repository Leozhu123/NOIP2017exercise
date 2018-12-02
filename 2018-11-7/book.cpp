#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <ctime>
#include <set>
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
LL f[maxn];
LL h[maxn],w[maxn];
int n, l;
int main(){
    freopen("book.in","r",stdin);
    freopen("book.out", "w", stdout);
    read(n);
    read(l);
    for(int i=1;i<=n;i++){
        read(h[i]);
        read(w[i]);
    }
    for(int i=1;i<=n;i++){
        LL sum = 0;
        LL mx = 0;
        f[i] = LLONG_MAX;
        for (int j = 1; j <= n; j++)
        {
            if(i-j<0)
                break;
            sum += w[i - j + 1];
            if(sum>l)
                break;
            mx=max(mx,h[i - j + 1]);
            f[i] = min(f[i], f[i - j] + mx);
        }
    }
    cout << f[n] << endl;
}
