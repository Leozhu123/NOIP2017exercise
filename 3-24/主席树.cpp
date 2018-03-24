#include <iostream>
using namespace std;
const int maxn = 210000;
struct Node
{
    int sum, l, r;
    Node *lch, *rch;
    Node(int s, int l, int r) : sum(s), l(l), r(r)
    {
        lch = rch = 0;
    }
};
Node *root[maxn];
void build(Node *&curr, int l, int r)
{
    curr = new Node(0, l, r);
    int mid = (l + r) >> 1;
    if (l < r)
    {
        build(curr->lch, l, mid);
        build(curr->rch, mid + 1, r);
    }
}
void update(Node *curr,Node *pre,int x){
    curr->sum=pre->sum+1;
    if(l==r) return;
    int mid=(curr->l+curr->r)>>1;
    if (x<=mid){
        curr->lch=new Node(0,curr->l,mid);
        curr->rch=pre->rch;
        update(curr->lch, pre->lch, x);
    }else{
        curr->rch=new Node(0,mid+1,curr->r);
        curr->lch=pre->lch;
        update(curr->rch, pre->rch, x);
    }
}