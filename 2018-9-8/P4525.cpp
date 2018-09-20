#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
const double eps = 1e-10;
double a,b,c,d,L,R;
inline double F(double x) {
    return (c * x + d) / (a * x + b);
}
inline double simpson(double a,double b) {
  double c=a+(b-a)/2;
  return (F(a)+4*F(c)+F(b))*(b-a)/6;
}
double asr(double a,double b,double eps,double S) {
  double c=a+(b-a)/2;
  double lS=simpson(a,c),rS=simpson(c,b);
  if(fabs(lS+rS-S)<=15*eps) return lS+rS+(lS+rS-S)/15.0;
  return asr(a,c,eps/2,lS)+asr(c,b,eps/2,rS);
}
int main(){
    cin >> a >> b >> c >> d >> L >> R;
    printf("%.6lf", asr(L, R, eps, 0));
}
