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
int n, m, k;
namespace solve1{
    const int maxn = 205;
    int a[maxn][maxn];
    void solve()
    {
        LL ans = 0;
        for(int i=1;i<=n;i++){
            int r, s, t;
            read(r);
            read(s);
            read(t);
            for (int j = 1; j <= r;j++){
                for (int k = s + m + 1; k <= t + m ;k++){
                    a[j][k]++;
                }
            }
        }
        for (int i = 1; i <= 200;i++){
            for (int j = 1; j <= 200;j++){
                if(a[i][j]>=k)
                    ans += 2 * i - 1;
            }
        }
        cout << ans;
    }
};
namespace solve2{
    const int maxn = 100005;
    int a[maxn];
    void solve()
    {
        LL ans = 0;
        int rr = 0;
        for(int i=1;i<=n;i++){
            int r, s, t;
            read(r);
            rr = r;
            read(s);
            read(t);
            a[s+m+1]++;
            a[t + m + 1]--;
        }
        for (int i = 1; i <= 2 * m + 1;i++){
            a[i]+=a[i-1];
            if(a[i]>=k)
                ans += rr * rr;
        }
        cout << ans;
    }
};
namespace solve3{
    const int maxn = 100005;
    int cover[maxn << 2];
    int sum[maxn << 2]; 
    void getup(int rt, int l, int r)
    {
        if (cover[rt])
            sum[rt] = r-l;
        else if (l == r)
            sum[rt] = 0;
        else
            sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void update(int rt, int l, int r, int L, int R, int c)
    {
        if (L <= l && r <= R)
        {
            cover[rt] += c;
            getup(rt, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        if (mid > L)
            update(rt << 1, l, mid, L, R, c);
        if (mid < R)
            update(rt << 1 | 1, mid, r, L, R, c);
        getup(rt, l, r);
    }
    struct circle{
        int r, s, t;
        bool operator<(const circle &rr) const{
            return r > rr.r;
        }
    };
    circle c[maxn];
    void solve(){
        for (int i = 1; i <= n;i++){
            read(c[i].r);
            read(c[i].s);
            read(c[i].t);
        }
        sort(c + 1, c + n + 1);
        LL ans = 0;
        for (int i = 1; i <= n;i++){
            if(c[i].s<c[i].t){
                update(1, 1, 2 * m + 1, c[i].s + m + 1, c[i].t + m + 1, 1);
            }else{
                update(1, 1, 2 * m + 1, c[i].s + m + 1, m + m + 1, 1);
                update(1, 1, 2 * m + 1, 1, c[i].t + m + 1, 1);
            }
            //cout<<sum[1]<<endl;
            ans += sum[1] * (c[i].r * c[i].r) - (c[i + 1].r * c[i + 1].r);
        }
        cout << ans;
    }
}
int main(){
    freopen("xiaoqiao.in","r",stdin);
    freopen("xiaoqiao.out", "w", stdout);
    read(n);
    read(m);
    read(k);
    if(n<=100)
        solve1::solve();
    else if(k==1)
        solve3::solve();
    else
        solve2::solve();
}