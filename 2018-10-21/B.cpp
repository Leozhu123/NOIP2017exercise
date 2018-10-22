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
using namespace std;
const int maxn = 100010;
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
int a[maxn], b[maxn], t[maxn];
int dfs(int pos){

}
int main(){
    int n;
    read(n);
    for(int i=1;i<=n-1;i++){
        read(a[i]);
    }
    for(int i=1;i<=n-1;i++){
        read(b[i]);
    }
    if(a[1]<b[1]){
        puts("NO");
        return 0;
    }
    if(a[2]<b[2]){
        puts("NO");
        return 0;
    }
    if(a[1]==a[2]){
        t[2]=a[1];
        t[1]=b[1];
        t[3]=b[2];
    }else if(a[1]==b[2]){
        t[2]=a[1];
        t[1]=b[1];
        t[3]=a[2];
    }else if(b[1]==a[2]){
        t[2]=b[1];
        t[1]=a[1];
        t[3] = b[2];
    }else if(b[1]==b[2]){
        t[2]=b[1];
        t[1]=a[1];
        t[3]=a[3];
    }else {
        puts("NO");
        return 0;
    }
    for (int i = 3;i<=n;i++){
        if(a[i]<b[i]){
            puts("NO");
            return 0;
        }
        if(a[i]==2 && b[i]==1) {
            puts("NO");
            return 0;
        }
        if(t[i]==a[i]){
            t[i + 1] = b[i];
        }else if(t[i]==b[i]){
            t[i + 1] = a[i];
        }else{
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 1; i <= n;i++){
        cout << t[i] << " ";
    }
}