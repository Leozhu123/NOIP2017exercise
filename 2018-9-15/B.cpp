#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define LL long long
#define IT set<node>::iterator 
using namespace std;
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
    if (it != s.end() && it->l == pos)  
        return it;
    --it;
    int L = it->l, R = it->r; 
    LL V = it->v; 
    s.erase(it);  
    s.insert(node(L, pos-1, V));  
    return s.insert(node(pos, R, V)).first; 
}
void assign_val(int l, int r, LL val)
{
    IT itl = split(l),itr = split(r+1); 
    s.erase(itl, itr);  
    s.insert(node(l, r, val));  
}
int main(){
    int n,m,ss,q;
    cin>>n>>m>>ss>>q;
    s.insert(node(1, m-1, 1));
    s.insert(node(m, m, 0));
    int l = 1, r = m-1;
    for (int i = 1; i <= ss;i++){
        int a,b;
        cin>>a>>b;
        int aa = a % m;
        if(aa==0)
            aa = m;
        int bb = b % m;
        if(bb==0)
            bb = m;
        if(((a-1)/m)==((b-1)/m)-1){
            r = min(r, m - bb);
            l = max(l, m - aa + 1);
            if(l-1>=1)
                assign_val(1,l-1,0);
            if(m-1>=r+1)
                assign_val(r+1,m-1,0);
        }else if(((a-1)/m)==((b-1)/m)){
            if(m - bb + 1<=m-aa && m-aa<=m-1)
                assign_val(m - bb + 1,m - aa,0);
        }else{
            cout << "Impossible!";
            return 0;
        }
    }
    int cnt=0;
    int p = -1;
    for (IT it = s.begin();it!=s.end();it++){
        if(it->v==1){
            cnt+=it->r-it->l+1;
            p = it->l;
        }
     //   cout << it->l << " " << it->r <<" "<<it->v<< endl;
        if(cnt>=2)
            break;
    }
    if (cnt >= 2)
    {
        cout << "Uncertain!";
        return 0;
    }
    else if (cnt == 0)
    {
        cout << "Impossible!";
        return 0;
    }
    int ans = 0;
    for (int i=1;i<=q;i++){
        int x;
        cin>>x;
        if(x>n*n-l)
            {
                ans ^= 0;
                ans ^= 0;
            }
        int ax,ay;
        x+=p;
        ax=((x-1)/m)+1;
        ay=((x-1)%m)+1;
      //  cout << ax << " " << ay << endl;
        if(ay==0)
            ay = m;
        ans^=ax;
        ans ^= ay;
    }
    cout << ans;
}