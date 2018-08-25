#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>
using namespace std;
const long long maxn = 200010;
struct Num{
    long long num;
    long long w;
    Num(long long n=0,long long w=0):num(n),w(w){}
};
Num a[maxn];
map<long long,long long> mo[50];
int main(){
    long long n, k;
    long long maxcnt = 15;
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        long long num = 0;
        long long cnt = 0;
        char ch;
        ch = getchar();
        while(!isdigit(ch))
            ch = getchar();
        while(isdigit(ch)){
            cnt++;
            num = num * 10 + ch - '0';
            ch = getchar();
        }
        a[i] = Num(num, cnt);
        maxcnt = max(maxcnt, cnt);
        mo[cnt][(num +k)% k]++;
     //   cout << cnt << " " << num % k << endl;
    }
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        long long t=a[i].num;
        for (long long j = 1; j <= maxcnt;j++){
            t*=10;
            t %= k;
            long long mm = t % k;
            ans += mo[j][(k+k - mm)%k];
            if(mo[j][(k - mm)%k]>0 && a[i].w==j && ((t+a[i].num)%k)==0)
                ans--;
        }
    }
    cout << ans;
}