#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>

#define il inline
#define npt nullptr
#define gc getchar
#define rep(I, A, B) for (int I = A; I <= B; ++I)
#define for2(I) for (int I = 0; I <= 1; ++I)

template <class T> il void read(T& t) {
    int f = 0, c = gc(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) t = t * 10 + c - 48, c = gc();
    if (f) t = -t;
}
template <class T, class... Args> il void
read(T& t, Args&... args) { read(t); read(args...); }

using namespace std;
int da[10000], aa[10000];
int n, m;
int main(){
    read(n, m);
    for(int i=1;i<=n;i++){
        read(da[i]);
    }
    for (int i=0;i<m;i++){
        char ch;
        cin>>ch;
        if(ch=='Q'){
            int a, b, c;
            int j,k;
            read(a, b, c);
            for (j = a, k = 0; j <= b;j++,k++){
                aa[k] = da[j];
            }
            sort(aa,aa+k);
            printf("%d\n", aa[c - 1]);
        }else{
            int a,b;
            read(a, b);
            da[a] = b;
        }
    }
}