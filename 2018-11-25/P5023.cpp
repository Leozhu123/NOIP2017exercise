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
#include <set>
#include <cstdlib>
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
const int P=1e9+7;
LL qpow(LL a, int n){
    LL ans=1;
    while(n){
    	if(n&1) ans*=a;
		ans%=P;
		a*=a;a%=P;
    	n>>=1;
	}
	return ans;
}
LL t[10],t1[10];
void init(){
    t[4] = 912; 
	LL tmp = 160;
    for(int i=5; i <= 8; i++, (tmp*=2)%=P){
        t[i] = t[i-1]*8 - tmp;
        t[i] %= P;
    }
    tmp = 48;
    for(int i=4; i <= 8; ++i, (tmp*=2)%=P){
        t1[i] = t[i]*3 - tmp;
        t1[i] %= P;
    }
}
int n,m;
void solve1(){
    printf("%lld\n", (LL)qpow(2, m));
}
void solve2(){
    printf("%lld\n", (LL)4*qpow(3, m-1)%P);
}
void solve3(){
    printf("%lld\n", (LL)112*qpow(3,m-3)%P);
}
void solve4(){
    if(n == m){
        printf("%lld\n", t[n]);
    }
    else{
        printf("%lld\n", t1[n] * qpow(3, m-n-1) % P);
    }
}
int main(){
	init();
	read(n,m);
	if(n>m) swap(n,m);
	if(n == 1){
        solve1();
    }
    else if(n == 2){
        solve2();
    }
    else if(n == 3){
        solve3();
    }
    else{
        solve4();
    }
}
