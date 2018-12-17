#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <climits>

inline void read(int& t) {
    int f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
using namespace std;
const int maxn = 3 * 1e6 + 10;
int where[maxn];
struct Qurry{
    int l,r,id;
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
int color[maxn];
int a[maxn];
int out[maxn];
int n=0,m=0;
int ans=0;
inline void add(int val){
    ++color[val];
    int i=ans;
    while(color[i]) i++;
    ans=i;
}
inline void del(int val){
    --color[val];
    if(color[val]==0)
        ans=min(ans,val);
}
int Qnum=0, Cnum=0;
inline void moQueue(){
    int l = 1, r = 0;
    for (int i = 1;i<=Qnum;i++){
        while(l>Q[i].l)
            l--,add(a[l]);
        while(r<Q[i].r)
            r++,add(a[r]);
		while(l<Q[i].l) 
            del(a[l]),l++;
        while(r>Q[i].r)
            del(a[r]),r--;
        out[Q[i].id]= ans;
    }
    for(int i=1;i<=Qnum;i++){
        printf("%d\n",out[i]);
    }
}
int main()
{
    read(n);
    read(m);
	for(int i=1;i<=n;i++){
        read(a[i]);
    }
    int base=sqrt(n);
    for(int i=1;i<=n;i++){
        where[i] = (i - 1) / base + 1;
    }
    while(m--){
    	++Qnum;
        read(Q[Qnum].l);
        read(Q[Qnum].r);
        Q[Qnum].id=Qnum; 
    }
    sort(Q + 1, Q + Qnum + 1);
    moQueue();
    return 0;
}
