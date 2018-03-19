#include <iostream>
using namespace std;
struct Node{
	Node *lch,*rch;
	int lc,rc,delta,sum;
	Node(int l,int r){
		lc=l;
		rc=r;
		delta=0;
		sum=0;
		lch=rch=0;
	}
	bool out(int l,int r){
		return r<lc || l>rc;
	}
	bool cover(int l,int r){
		return l<=lc && r>=rc;
	}
	void pushdown(){
		