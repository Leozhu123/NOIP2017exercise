#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
#define P pair<pair<int,int>,int>
#define MP make_pair
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
const int maxn=3e5+5;
int n, m;
P dish[maxn];
int idx[maxn];
int main(){
    read(n, m);
    for (int i = 1; i <= n;i++){
        read(dish[i].first.second);
        dish[i].second = i;
    }
    for(int i=1;i<=n;i++){
        read(dish[i].first.first);
    }
    sort(dish+1,dish+n+1);
    for(int i=1;i<=n;i++){
        idx[dish[i].second] = i;
    }
    int p = 1;
    for (int i = 1;i<=m;i++){
        LL ans = 0;
        int x,y;
        read(x, y);
        int tmp = min(dish[idx[x]].first.second, y);
        ans += (LL)dish[idx[x]].first.first * tmp;
        dish[idx[x]].first.second -= tmp;
        y -= tmp;
        while(y && p<=n){
            int tmp = min(dish[p].first.second, y);
            dish[p].first.second -= tmp;
            y -= tmp;
            ans += (LL)dish[p].first.first * tmp;
            if(!dish[p].first.second)
                p++;
        }
        if(y>0)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
}