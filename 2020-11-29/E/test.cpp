//by ciwomuli
//enter ICPC WF 2020
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
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

struct node
{
    int p;
    double x;
    node() {}
    node(double xx, int pp)
    {
        x = xx;
        p = pp;
    }
};
const int maxn = 2e5 + 5;
node que1[maxn], que2[maxn];
int head1 = 1, tail1 = 1, head2 = 1, tail2 = 1;
int cnt = 0;
int n, m;
void push(double v)
{
    cnt++;
    while (head1 <= tail1 && que1[tail1].x <= v)
        tail1--;                  //删尾
    que1[++tail1] = node(v, cnt); //得到最优解并插入
    while (cnt - que1[head1].p >= m)
        head1++; //去头
    while (head2 <= tail2 && que2[tail2].x >= v)
        tail2--;                  //删尾
    que2[++tail2] = node(v, cnt); //得到最优解并插入
    while (cnt - que2[head2].p >= m)
        head2++; //去头
}
int u;
double v;
int main()
{
    read(n, m);
    read(u);
    scanf("%lf", &v);
    cnt = 1;
    que1[1] = que2[1] = node(v, 1);
    for (int i = 2; i <= n;i++){
        read(u);
        if(u == 1){
            scanf("%lf", &v);
            push(v);
        }else{
            double mx = que1[head1].x;
            double mi = que2[head2].x;
            double ans = (mx + mi) / 2;
            printf("%.1lf\n", ans);
        }
    }
}