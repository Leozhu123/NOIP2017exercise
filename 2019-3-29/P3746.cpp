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
#include <regex>
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
LL n,p,k,r;
LL A[55][55], R[55][55], T[55][55];
#define F(i,a) for(int i=0;i<a;i++)
int main(){
    read(n,p,k,r);
    F(i,k){
        A[i][i]++;
        A[i][(i - 1 + k) % k]++;
        R[i][i] = 1;
    }
    LL b = n * k;
    while(b){
        if(b&1){
            F(i, k)
            F(j, k) T[i][j] = R[i][j],
                    R[i][j] = 0;
            F(i, k)
            F(j, k) F(l, k) R[i][j] = ((LL)R[i][j] + A[i][l] * T[l][j] % p) % p;
        }
        F(i,k)F(j,k)T[i][j]=A[i][j],A[i][j]=0;b>>=1;
        F(i,k)F(j,k)F(l,k)A[i][j]=((LL)A[i][j]+T[i][l]*T[l][j]%p)%p;
    }
    cout << R[0][r] % p;
}