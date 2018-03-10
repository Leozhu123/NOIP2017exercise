#include <iostream>
using namespace std;
struct Node{
    Node *lch,*rch;
    long long delta, sum, lc, rc;
    Node (long long l,long long r){
        lc = l;
        rc = r;
        lch=rch=0;
        sum=delta=0;
    }
    long long size(){
        return rc-lc+1;
    }
    bool cover(long long l,long long r){
        return l<=lc && r>=rc;
    }
    bool out(long long l,long long r){
        return r<lc || l>rc;
    }
    void pushdown(){
        if (lch){
            lch->sum+=delta*lch->size();
            lch->delta+=delta;
        }
        if (rch){
            rch->sum+=delta*rch->size();
            rch->delta+=delta;
        }
        delta=0;
    }
    void getup(){
        sum=0;
        if (lch){
            sum+=lch->sum;
        }
        if (rch){
            sum+=rch->sum;
        }
    }
};
Node *root;
long long a[400000];
void build(Node*& curr,long long l,long long r){
    curr=new Node(l,r);
    if (l==r){
        curr->sum=a[l];
        return;
    }
    long long mid=(l+r)>>1;
    build(curr->lch,l,mid);
    build(curr->rch,mid+1,r);
    curr->getup();
;}
void modify(Node* curr,long long l,long long r,long long a){
    if (curr->out(l,r)) return;
    if (curr->cover(l,r)){
        curr->sum+=a*curr->size();
        curr->delta+=a;
        return;
    }
    curr->pushdown();
    if(curr->lch) 
        modify(curr->lch,l,r,a);
    if(curr->rch)
        modify(curr->rch,l,r,a);
    curr->getup();
}
long long qurry(Node * curr,long long l,long long r){
    if (curr->out(l,r)) return 0;
    if (curr->cover(l,r)){
        return curr->sum;
    }
    curr->pushdown();
    long long sum=0;
    if (curr->lch) sum+=qurry(curr->lch,l,r);
    if (curr->rch) sum+=qurry(curr->rch,l,r);
    return sum;
}
int main(){
    long long n,m;
    cin>>n>>m;
    for (long long i=1;i<=n;i++){
        cin>>a[i];
    }
    build(root,1,n);
    for (long long i=0;i<m;i++){
        long long x;
        cin>>x;
        if (x==1){
            long long a,b,c;
            cin>>a>>b>>c;
            modify(root,a,b,c);
        }else if (x==2){
            long long x,y;
            cin>>x>>y;
            cout<<qurry(root,x,y)<<endl;
        }
    }
}
