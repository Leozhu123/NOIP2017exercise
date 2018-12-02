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
const int maxn = 1000005;
int n;
char str1[maxn],str2[maxn];
int a[maxn],C[maxn];
int lowbit(int x){
    return x & -x;
}
void add(int x,int a){
    while(x<=n){
        C[x]+=a;
        x += lowbit(x);
    }
}
int sum(int x){
    int ans = 0;
    while(x>0){
        ans+=C[x];
        x -= lowbit(x);
    }
    return ans;
}
queue<int> q[26];
int main(){
    freopen("letter.in","r",stdin);
    freopen("letter.out", "w", stdout);
    read(n);
    scanf("%s",str1+1);
    scanf("%s", str2 + 1);
    for(int i=1;i<=n;i++){
        q[str1[i] - 'A'].push(i);
    }
    for(int i=1;i<=n;i++){
        a[i]=q[str2[i]-'A'].front();
        q[str2[i]-'A'].pop();
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans += sum(n + 1 - a[i]);
        add(n + 1 - a[i], 1);
    }
    cout << ans;
}