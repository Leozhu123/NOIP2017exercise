//by ciwomuli
//AK JSOI 2019
//I love wyt
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
#include <sstream>
#define LL long long
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
int x[10], y[10], n;
bool used[10];
int ord[10];
int cnt;
double sum = 0;
int fact(int n){
    int ans = 1;
    for (int i = 1;i<=n;i++) ans *=i;
    return ans;
}
void work(int curr){
    if(curr == n+1) {
        double tmp = 0;
        for (int i = 1; i < n;i++){
            tmp += sqrt((x[ord[i]] - x[ord[i + 1]]) * (x[ord[i]] - x[ord[i + 1]]) + (y[ord[i]] - y[ord[i + 1]]) * (y[ord[i]] - y[ord[i + 1]]));
        }
        //tmp += sqrt((x[n] - x[1]) * (x[n] - x[1]) + (y[n] - y[1]) * (y[n] - y[1]));
        sum+=tmp;
        return;
    }
    for (int i = 1; i <= n;i++){
        if(!used[i]){
            ord[curr] = i;
            used[i] = true;
            work(curr + 1);
            used[i] = false;
        }
    }
}
int main(){
    read(n);
    for (int i = 1;i<=n;i++){
        read(x[i], y[i]);
    }
    work(1);
    printf("%.08lf", sum / fact(n));
}