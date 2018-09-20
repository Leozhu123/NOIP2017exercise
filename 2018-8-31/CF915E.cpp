#pragma GCC optimize(2) 
#include<cstdio>
#include<set>
#include<vector>
#include<utility>
#include <iostream>
#include<algorithm>
using namespace std;
#define IT set<node>::iterator

using std::set;
using std::vector;
using std::pair;

#define LL int
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int imax_n = 1e9 + 7;


struct node
{
    int l,r;
    mutable LL v;
    node(int L, int R=-1, LL V=0):l(L), r(R), v(V) {}
    bool operator<(const node& o) const
    {
        return l < o.l;
    }
};

set<node> s;

IT split(int pos)
{
    IT it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos) return it;
    --it;
    int L = it->l, R = it->r;
    LL V = it->v;
    s.erase(it);
    s.insert(node(L, pos-1, V));
    return s.insert(node(pos, R, V)).first;
}

void add(int l, int r, LL val=1)
{
    IT itl = split(l),itr = split(r+1);
    for (; itl != itr; ++itl) itl->v += val;
}

void assign_val(int l, int r, LL val=0)
{
    IT itl = split(l),itr = split(r+1);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}

LL rank(int l, int r, int k)
{
    vector<pair<LL, int> > vp;
    IT itl = split(l),itr = split(r+1);
    vp.clear();
    for (; itl != itr; ++itl)
        vp.push_back(pair<LL,int>(itl->v, itl->r - itl->l + 1));
    std::sort(vp.begin(), vp.end());
    for (vector<pair<LL,int> >::iterator it=vp.begin();it!=vp.end();++it)
    {
        k -= it->second;
        if (k <= 0) return it->first;
    }
    return -1LL;
}

LL sum(int l, int r)
{
    IT itl = split(l),itr = split(r+1);
    LL res = 0;
    for (; itl != itr; ++itl)
        res = res + (LL)(itl->r - itl->l + 1) * itl->v;
    return res;
}

int n, q;

int main()
{
    scanf("%d%d",&n,&q);
    s.insert(node(1,n,1));
    s.insert(node(n+1, n+1, 0));
    int lines = 0;
    for (int i =1; i <= q; ++i)
    {
        int k,l,r;
        cin>>l>>r>>k;
        if (l > r)
            std::swap(l,r);
        if (k==1)
            assign_val(l, r, LL(0)),cout<<sum(1,n)<<endl;
        else assign_val(l, r, LL(1)),cout<<sum(1,n)<<endl;
    }
    return 0;
}//2333333