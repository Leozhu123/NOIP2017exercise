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
const int maxn=210;
int f[maxn][maxn*maxn];
int sum[maxn];
struct node{
    int a,b;
    bool operator<(const node &r) const{
        return b > r.b;
    }
};
node nodes[maxn];
int n;
int main(){
    read(n);
    for(int i=1;i<=n;i++)
        read(nodes[i].a, nodes[i].b);
    sort(nodes + 1, nodes + n + 1);
    for(int i=1;i<=n;i++)
        sum[i] = sum[i - 1] + nodes[i].a;
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn*maxn;j++)
            f[i][j] = INT_MAX;
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum[i];j++){
            if(j>=nodes[i].a){
                f[i][j] = min(f[i][j], max(f[i - 1][j - nodes[i].a], j + nodes[i].b));
            }
            f[i][j] = min(f[i][j], max(f[i - 1][j], sum[i] - j + nodes[i].b));
        }
    }
    int ans=INT_MAX;
    for(int i = 0; i <= sum[n]; i++)
        ans = min(ans, f[n][i]);
    printf("%d\n", ans);
    return 0;
}