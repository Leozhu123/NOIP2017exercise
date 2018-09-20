#include <iostream>
#include <algorithm>
using namespace std;
const long long maxn=100005;
struct Node{
	Node *lch,*rch;
	long long x,delta;
	Node(){
		delta=x=0;
		lch=rch=0;
	}
	void pushdown(long long l,long long r){
		long long mid=(l+r)>>1;
		lch->delta+=delta;
		rch->delta+=delta;
		lch->x+=delta*(mid-l+1);
		rch->x+=delta*(r-mid);
		delta=0;
	}
	void update(){
		x=lch->x+rch->x;
	}
};
long long a[maxn];
void build(Node *&curr,long long l,long long r){
	curr=new Node;
	if(l==r){
		curr->x=a[l];
		return;
	}
	long long mid=(l+r)>>1;
	build(curr->lch,l,mid);
	build(curr->rch,mid+1,r);
	curr->update();
}
void modify(Node *curr,long long l,long long r,long long lc,long long rc,long long add){
	if(lc<=l && r<=rc){
		curr->delta+=add;
		curr->x+=(r-l+1)*add;
		return;
	}
	long long mid=(l+r)>>1;
	curr->pushdown(l,r);
	if(mid>=lc){
		modify(curr->lch,l,mid,lc,rc,add);
	}
	if(mid+1<=rc){
		modify(curr->rch,mid+1,r,lc,rc,add);
	}
	curr->update();
	return;
}
long long quary(Node *curr,long long l,long long r,long long lc,long long rc){
	if(lc<=l && r<=rc){
		return curr->x;
	}
	long long mid=(l+r)>>1;
	curr->pushdown(l,r);
	long long ans=0;
	if(mid>=lc){
		ans+=quary(curr->lch,l,mid,lc,rc);
	}
	if(mid+1<=rc){
		ans+=quary(curr->rch,mid+1,r,lc,rc);
	}
	curr->update();
	return ans;
}
int main(){
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	Node *root;
	build(root,1,n);
	for(long long i=1;i<=m;i++){
		long long opt;
		cin>>opt;
		if(opt==1){
			long long l,r,x;
			cin>>l>>r>>x;
			modify(root,1,n,l,r,x);
		}else{
			long long l,r;
			cin>>l>>r;
			cout<<quary(root,1,n,l,r)<<endl;
		}
	}
}
