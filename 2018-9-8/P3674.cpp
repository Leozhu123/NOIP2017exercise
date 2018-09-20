#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <climits>
#include <bitset>
inline void read(int& t) {
    int f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
using namespace std;
const int maxn = 100000;
int where[maxn];
struct Qurry{
    int k,l,r,x,id;
    Qurry(){
        l = r = id  = 0;
    }
    bool operator< (const Qurry &r)const{
        if (where[l]==where[r.l]){
            if ((where[l]&1)==1) return this->r<r.r;
            else return this->r>r.r;    
        }
        return where[l] < where[r.l];
    }
};
Qurry Q[maxn];
int c[maxn];
int a[maxn];
int out[maxn];
int n=0,m=0;
int ans=0;
bitset<maxn+5> now1,now2;
inline void add(int x){
    if(c[x]++==0) now1[x]=1,now2[maxn-x]=1;
}
inline void del(int x){
    if(--c[x]==0) now1[x]=0,now2[maxn-x]=0;
}
int Qnum=0, Cnum=0;
inline void moQueue(){
    int l = 1, r = 0;
    for (int i = 1;i<=Qnum;i++){
        while(l<Q[i].l) 
            del(a[l]),l++;
        while(l>Q[i].l)
            l--,add(a[l]);
        while(r<Q[i].r)
            r++,add(a[r]);
        while(r>Q[i].r)
            del(a[r]),r--;
        int k=Q[i].k,x=Q[i].x;
        switch(k){
        	case 1:{
                if((now1&(now1<<x)).any())
                out[Q[i].id]=1;
                break;
            }
            case 2:{
                if((now1&(now2>>(maxn-x))).any())
                out[Q[i].id]=1;
                break;
            }
            case 3:{
                for(int j=1;j*j<=x;++j)
                if(!(x%j))
                if(now1[j]&&now1[x/j]){
                    out[Q[i].id]=1;break;
                }
                break;
            }
        }
    }
    for(int i=1;i<=Qnum;i++){
        puts(out[i]?"hana":"bi");
    }
}
int main()
{
    read(n);
    read(m);
    int base=sqrt(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
        where[i] = (i - 1) / base + 1;
    }
    while(m--){
    	++Qnum;
        read(Q[Qnum].k);
        read(Q[Qnum].l);
        read(Q[Qnum].r);
        read(Q[Qnum].x);
        Q[Qnum].id=Qnum; 
    }
    sort(Q + 1, Q + Qnum + 1);
    moQueue();
    return 0;
}
