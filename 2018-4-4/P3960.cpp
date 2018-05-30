#include <iostream>
using namespace std;
int n,m,q;
struct Node{
    Node *lch,*rch,*father;
    int l,r,sum,id;
    Node (int l=0,int r=0,int s=0,Node* f=0,int i=0):l(l),r(r),sum(s),id(i){
    	father=f;
        lch=rch=0;
    }
    void pushdown(){
        if(lch) return;
        int mid=(l+r)>>1;
        if(l>n){
            lch=new Node(l,mid,0,this);
            rch=new Node(mid+1,r,0,this);
            return;
        }
        if(mid>=n){
            lch=new Node(l,mid,n-l+1,this);
            rch=new Node(mid+1,r,0,this);
            return;
        }
        if(r>=n){
            lch=new Node(l,mid,mid-l+1,this);
            rch=new Node(mid+1,r,n-mid,this);
            return;
        }
        lch=new Node(l,mid,mid-l+1,this);
        rch=new Node(mid+1,r,r-mid),this;
        return;
    }
    void getup(){
        if(lch) sum=lch->sum+rch->sum;
    }
};
void change(Node *curr,int k,int a,int h,int id){
    if(curr->l==curr->r){
    	if(a==1) change(curr->father->rch,k,a,h,id);
        curr->sum=a;
        if(curr->id==0){
            if(h==0){
                curr->id=curr->l*n;
            }
            else curr->id=(h-1)*(n)+curr->l;
        }
        if(curr->id==0) curr->id=id;
        return;
    }
    curr->pushdown();
    if(curr->lch->sum>=k){
        change(curr->lch,k,a,h,id);
    } else {
        change(curr->rch,k-curr->lch->sum,a,h,id);
    }
    curr->getup();
}
Node* qurry(Node *curr,int k,int h){
    if(curr->l==curr->r){
        if(curr->id==0){
            if(h==0){
                curr->id=curr->l*n;
            }
            else curr->id=(h-1)*(n-1)+curr->l;
        }
        return curr; 
    }
    curr->pushdown();
    if(curr->lch->sum>=k){
        return qurry(curr->lch,k,h);
    } else {
        return qurry(curr->rch,k-curr->lch->sum,h);
    }
}   
Node *xroot[3000005],*yroot;
int main(){
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++) xroot[i]=new Node(1,6000000,n);
    yroot=new Node(1,6000000,m);
    for (int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        Node* tmp=qurry(xroot[x],y,x);
        cout<<tmp->id<<endl;
        //cout<<xroot[1]->sum<<endl;
        //cout<<xroot[1]->l<<" "<<xroot[1]->r<<endl;
        change(xroot[x],y,0,x,0);
        change(yroot,x,0,0,0);
        change(xroot[x],n-1,1,x,qurry(yroot,x,0)->id);
        change(yroot,m-1,1,0,tmp->id);
        change(xroot[m],n-1,1,m,tmp->id);
    }
}
