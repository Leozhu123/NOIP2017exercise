#include <algorithm>
#include <iostream>

using namespace std;
const int maxn = 20005;

int cyp[maxn];
int siz,dot;

inline int lowbit(int x){
    return x & (-x);
}
struct Node
{
    int sum, lb, rb;
    Node *lch, *rch;
    Node(int s, int l, int r) : sum(s), lb(l), rb(r), lch(0), rch(0) {}
};

Node *root[maxn], bt[maxn],use[maxn];

void build(Node *&curr, int l, int r)
{
    curr = new Node(0, l, r);
    int mid = (l + r) >> 1;
    if (l == r)
        return;
    build(curr->lch, l, mid);
    build(curr->rch, mid + 1, r);
    return;
}
void change(Node *curr,Node *pre,int x,int val){
    curr->sum=pre->sum+val;
    if(curr->lb==curr->rb)
        return;
    int mid = (curr->lb + curr->rb) >> 1;
    if(x<=mid){
        curr->lch=new Node(0,curr->lb,mid);
        curr->rch = pre->rch;
        change(curr->lch, pre->lch, x, val);
    }else{
        curr->rch=new Node(0,mid+1,curr->rb);
        curr->lch=pre->lch;
        change(curr->rch, pre->rch, x, val);
    }
}
int id(int x){
    return lower_bound(cyp, cyp + siz, x) - cyp;
}
void add(int now,int pos,int val){
    while(now<=dot){
        Node *tmp=new Node(0,1,siz);
        change(tmp,bt[now],pos,val);
        bt[now]=tmp;
        now += lowbit(now);
    }
}
int getsum(int x){
    int ans = 0;
    while(x>0){
        ans+=use[x]->lch->sum;
        x -= lowbit(x);
    }
    return ans;
}
int main(){

}