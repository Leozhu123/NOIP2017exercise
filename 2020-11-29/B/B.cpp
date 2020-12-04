//by ciwomuli
//both enter ICPC WF
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
int main (){
    long double a, b, c;
    cin >> a >> b >> c;
    long double S1, S2, S3, S4;
    S1 = a * b / 2;
    S2 = b * c / 2;
    S3 = a * c / 2;
    long double aa = sqrt(a * a + b * b);
    long double bb = sqrt(a * a + c * c);
    long double cc = sqrt(c * c + b * b);
    long double p = (aa + bb + cc) / 2;
    S4 = sqrt(p * (p - aa) * (p - bb) * (p - cc));
//    cout << S1 << " " << S2 << " " << S3 << " " << S4 << endl;
    long double V = a * b * c / 6;
    long double r = 3 * V / (S1 + S2 + S3 + S4);
    long double ans = 3.141592 * r * r * r * 4.0 / 3.0;
    printf("%.2Lf", ans);
}