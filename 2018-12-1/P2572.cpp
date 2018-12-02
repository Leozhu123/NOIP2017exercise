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
const int maxn=100005;
int aa[maxn];
int n, m;
int main(){
    read(n,m);
    for(int i=1;i<=n;i++) read(aa[i]);
    for(int i=1;i<=m;i++){
        int opt,a,b;
        read(opt,a,b);
        a++;
        b++;
        if(opt==0){
            int j;
            for(j=a;j<=b-4;j+=4){
                aa[j]=0;
                aa[j+1]=0;
                aa[j+2]=0;
                aa[j + 3] = 0;
            }
            for(;j<=b;j++)
                aa[j] = 0;
        }
        if(opt==1){
            int j;
            for(j=a;j<=b-4;j+=4){
                aa[j]=1;
                aa[j+1]=1;
                aa[j+2]=1;
                aa[j + 3] = 1;
            }
            for(;j<=b;j++)
                aa[j] = 1;
        }
        if(opt==2){
            int j;
            for(j=a;j<=b-4;j+=4){
                aa[j]^=1;
                aa[j+1]^=1;
                aa[j+2]^=1;
                aa[j + 3] ^= 1;
            }
            for(;j<=b;j++)
                aa[j] ^= 1;
        }
        if(opt==3){
            int j;
            int ans=0;
            for(j=a;j<=b-4;j+=4){
                ans += aa[j] + aa[j + 1] + aa[j + 2] + aa[j + 3];
            }
            for(;j<=b;j++)
                ans += aa[j];
            printf("%d\n", ans);
        }
        if(opt==4){
            int cnt = 0;
            int ans = 0;
            for(int j=a;j<=b;j++){
                if(aa[j]) cnt++;
                else cnt=0;
                ans = max(ans, cnt);
            }
            printf("%d\n", ans);
        }
    }
}