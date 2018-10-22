#include <cctype>
#include <cstdio>
#include <climits>
#include <algorithm>

template <typename T> inline void read(T& t) {
    int f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
#if __cplusplus >= 201103L
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
    read(t); read(args...);
}
#else
template <typename T1, typename T2>
inline void read(T1& t1, T2& t2) { read(t1); read(t2); }
template <typename T1, typename T2, typename T3>
inline void read(T1& t1, T2& t2, T3& t3) { read(t1, t2); read(t3); }
template <typename T1, typename T2, typename T3, typename T4>
inline void read(T1& t1, T2& t2, T3& t3, T4& t4) { read(t1, t2, t3); read(t4); }
template <typename T1, typename T2, typename T3, typename T4, typename T5>
inline void read(T1& t1, T2& t2, T3& t3, T4& t4, T5& t5) { read(t1, t2, t3, t4); read(t5); }
#endif	// C++11

using namespace std;
#define LL long long
const int maxn = 200005;
struct Node{
    LL x;
    Node *lch, *rch;
};
Node *root[maxn];
void update(Node *&curr,Node *pre,int l,int r,int x){
    if(curr==0){
        curr=new Node();
        if(pre==0){
            curr->x = 1;
        }else{
            curr->x = pre->x + 1;
        }
    }else{
        curr->x = pre->x + 1;
    }
    if(l==r)
        return;
    int mid = (l + r) >> 1;
    if(x<=mid){
        curr->rch = pre == 0 ? 0 : pre->rch;
        update(curr->lch, pre == 0 ? 0 : pre->lch, l, mid, x);
    }else{
        curr->lch = pre == 0 ? 0 : pre->lch;
        update(curr->rch, pre == 0 ? 0 : pre->rch, mid+1, r, x);
    }
}
LL qurry(Node *st,Node *ed,int l,int r,LL x){
    if(l==r)
        return l;
    LL s = (ed?(ed->lch ? ed->lch->x : 0):0) - (st?(st->lch ? st->lch->x : 0):0);
    int mid = (l + r) >> 1;
    if(x<=s){
        return qurry(st?st->lch:0, ed?ed->lch:0, l, mid, x);
    }else{
        return qurry(st?st->rch:0, ed?ed->rch:0, mid + 1, r, x - s);
    }
}
int n, q;
LL num[maxn], num2[maxn];
int main()
{
    read(n, q);
    for (int i = 1; i <= n; i++)
    {
        read(num[i]);
        num2[i] = num[i];
    }
    sort(num2 + 1, num2 + 1 + n);
    int size = unique(num2 + 1, num2 + n + 1) - (num2 + 1);
    for (int i = 1; i <= n; i++)
    {
        LL t = lower_bound(num2 + 1, num2 + 1 + size, num[i]) - num2;
        update(root[i], root[i - 1], 1, size, t);
    }
    for (int i = 1; i <= q; i++)
    {
        LL x, y, z;
        read(x, y, z);
        printf("%lld",num2[qurry(root[x-1], root[y], 1,size,z)]);
    }
}