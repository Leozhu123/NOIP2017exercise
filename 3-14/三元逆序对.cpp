#include <bits/stdc++.h> 
#define LL long long
#define INF 1<<30
#define MAXN 60000
#define MAXM 32767
using namespace std;
struct Node{
 int l,r,lc,rc,v; 
} ;
class SegmentTree{
	public:
		int root,z;
		Node p[11* MAXM];	
void set(){
			root=z=-1;
		}
 
void build(int &k,int l,int r){
	k=++z;
	p[k].l=l;
	p[k].r=r;
	p[k].lc=p[k].rc=-1;
	p[k].v=0;
	if(l!=r){
	 	build(p[k].lc,l,(l+r)/2);
	 	build(p[k].rc,(l+r)/2+1,r);
	}
}
void insert(int &k,int tag){
	p[k].v++;
	if(p[k].lc==-1) return;
	if(tag<=p[p[k].lc].r)
		insert(p[k].lc,tag);
	else 
	    insert(p[k].rc,tag);
}
int search(int &k,int tag){
	if(tag==p[k].r) return p[k].v;
	if(tag>p[p[k].lc].r)
		return p[p[k].lc].v+search(p[k].rc,tag);
	else
	    return search(p[k].lc,tag);
}
};
int a[MAXN];
SegmentTree t;
int l[MAXN],r[MAXN];
int main()
{ 
	int n;

	scanf("%d",&n);
	t.set();
	t.build(t.root,0,MAXM);

	for (long long i=1 ;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=0)
		l[i]=t.search(t.root,a[i]-1);
		t.insert(t.root,a[i]);
	} 
	t.set();
	t.build(t.root,0,MAXM);
	for (long long i=1;i<=n;i++){
		if(a[i]!=0)
		r[i]=t.search(t.root,a[i]-1);
		t.insert(t.root,a[i]);	
	}
	LL ans=0;
	for (long long i=1 ;i<=n;++i)
		ans+=(LL)l[i]*r[i];
	cout<<ans<<endl;
	return 0;
} 
