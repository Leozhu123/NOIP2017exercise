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
const int maxn = 2000005;
int a[maxn];
int fa[maxn];
int findfa(int x){
    return fa[x] == x ? x : fa[x]=findfa(fa[x]);
}
struct seg{
    int x1, x2, e;
    bool operator<(const seg &r) const{
        return e > r.e;
    }
};
seg segs[maxn];
int n,m;
void init(){
    memset(a,0,sizeof(a));
    memset(segs, 0, sizeof(segs));
}
int main(){
    int T;
    read(T);
    while(T--){
        init();
        read(n);
        for(int i=1;i<=n;i++){
            read(segs[i].x1, segs[i].x2,segs[i].e);
            a[(i-1)*2]=segs[i].x1;
            a[(i-1)*2+1]=segs[i].x2;
        }
        for (int i = 0;i<maxn;i++)
            fa[i] = i;
        sort(a, a + 2 * n);
        sort(segs + 1, segs + n + 1);
        bool flag = true;
        int cnt = unique(a, a + 2 * n) - a;
        for (int i = 1; i <= n;i++){
            int fa1 = findfa(lower_bound(a, a + cnt, segs[i].x1) - a);
            int fa2 = findfa(lower_bound(a, a + cnt, segs[i].x2) - a);
            if(segs[i].e==1){
                if(fa1!=fa2)
                    fa[fa1] = fa2;
            }else{
                if(fa1==fa2){
                    flag = 0;
                    puts("NO");
                    break;
                }
            }
        }
        if(flag)
            puts("YES");
    }
}