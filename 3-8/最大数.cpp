#include <iostream>
using namespace std;
long long mod=0;
struct Node{
    Node *lch,*rch;
    long long  max, lc, rc;
    Node (long long l,long long r){
        lc = l;
        rc = r;
        lch=rch=0;
        max=0;
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
    void getup(){
        if (lch){
            max=lch->max;
        }
        if (rch){
            if(rch->max>max) max=rch->max;
        }
    }
};
Node *root;
long long a[400000];
void modify(Node* curr,long long p,long long a){
    if(curr->lc==curr->rc){
        curr->max=a%mod;
        return;
    }
    if(p<=curr->lch->rc) modify(curr->lch,p,a);
    else modify(curr->rch,p,a);
    curr->getup();
    return;
}
long long qurry(Node * curr,long long l,long long r){
    if (curr->out(l,r)) return 0;
    if (curr->cover(l,r)){
        return curr->max;
    }
    long long max=0;
    if (curr->lch) max=qurry(curr->lch,l,r);
    if (curr->rch) {
        int t=qurry(curr->rch,l,r);
        if(t>max)max=t;
        }

    return max%mod;
}
int main(){
    long long n;
    long long t=0,size=0;;
    cin>>n>>mod;
    for (int i=0;i<n;i++){
        char ch;
        cin>>ch;
        if (ch=="A"){
            int
        }
    }
}
