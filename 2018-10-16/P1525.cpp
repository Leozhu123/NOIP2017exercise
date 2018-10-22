#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
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
struct data{
    int x, y, z;
};
data f[maxn];
int n,m,a[maxn],b[maxn];
bool cmp(const data &a,const data &b){
    return a.z > b.z;
}
int find(int x){
    return x == a[x] ? x : a[x] = find(a[x]);
}
void ad(int x,int y){
    x=find(a[x]);
    y=find(a[y]);
    a[x] = y;
}
bool check(int x,int y){
    return find(a[x]) == find(a[y]);
}
int main(){
    read(n, m);
    for(int i=1;i<=n;i++)
        a[i] = i;
    for(int i=1;i<=m;i++){
        read(f[i].x, f[i].y, f[i].z);
    }
    sort(f + 1, f + m + 1, cmp);
    for (int i = 1; i <= m + 1;i++){
        if(check(f[i].x,f[i].y)){
            printf("%d",f[i].z);
            break;
        }
        else{
            if(!b[f[i].x])
                b[f[i].x] = f[i].y;
            else{
                ad(b[f[i].x], f[i].y);
            }
            if(!b[f[i].y])
                b[f[i].y] = f[i].x;
            else{
                ad(b[f[i].y], f[i].x);
            }
        }
    }
    return 0;
}