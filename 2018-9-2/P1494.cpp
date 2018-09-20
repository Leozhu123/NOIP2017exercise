#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <climits>

template <typename T> inline void read(T& t) {
    long long f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
    read(t); read(args...);
}
using namespace std;
const long long maxn = 3 * 1e6 + 10;
long long where[maxn];
struct Qurry{
    long long l,r,id;
    Qurry(){
        l = r = id  = 0;
    }
    bool operator< (const Qurry &r)const{
        if (where[l]==where[r.l]){
            if (where[l]&1==1) return this->r<r.r;
            else return this->r>r.r;    
        }
        return where[l] < where[r.l];
    }
};
long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
Qurry Q[maxn];
long long color[maxn];
long long a[maxn];
long long out[maxn][2];
long long n=0,m=0;
long long ans=0;
void add(long long val){
    if(color[val]>1)
        ans-=(color[val]*(color[val]-1)/2);
    ++color[val];
    if(color[val]>1)
        ans+=(color[val]*(color[val]-1)/2);
}
void del(long long val){
    if(color[val]>1)
        ans-=(color[val]*(color[val]-1)/2);
    --color[val];
    if(color[val]>1)
        ans+=(color[val]*(color[val]-1)/2);
}
long long Qnum=0, Cnum=0;
void moQueue(){
    long long l = 1, r = 0, now = 0;
    for (long long i = 1;i<=Qnum;i++){
    	if(Q[i].l==Q[i].r){
    		out[Q[i].id][0] = 0;
        	out[Q[i].id][1] = 1;
        	continue;
    	}
        while(l<Q[i].l) 
            del(a[l]),l++;
        while(l>Q[i].l)
            l--,add(a[l]);
        while(r<Q[i].r)
            r++,add(a[r]);
        while(r>Q[i].r)
            del(a[r]),r--;
        out[Q[i].id][0] = ans;
        out[Q[i].id][1] = (r-l+1)*(r-l)/2;
    }
    for(long long i=1;i<=Qnum;i++){
    	if(out[i][0]==0){
    		puts("0/1");
    		continue;
    	}
    	long long g=gcd(out[i][0],out[i][1]);
        printf("%lld/%lld\n",out[i][0]/g,out[i][1]/g);
    }
}
int main()
{
    read(n,m);
    long long base=sqrt(n);
    for(long long i=1;i<=n;i++){
        read(a[i]);
        where[i] = (i - 1) / base + 1;
    }
    while(m--){
    	++Qnum;
        read(Q[Qnum].l,Q[Qnum].r);
        Q[Qnum].id=Qnum; 
    }
    sort(Q + 1, Q + Qnum + 1);
    moQueue();
    return 0;
}
