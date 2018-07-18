#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
struct Node{
    long long x;
    long long sz;
    long long times;
    Node *lch,*rch;
    long long pos;
    Node(){
        x=sz=times=0;
        lch=rch=0;
        pos=rand();
    }
    void maintain(){
        sz=times+lch->sz+rch->sz;
    }
};
Node *null=new Node();
Node *root=null;
void rightroute(Node *&curr){
    	Node *t=curr->lch;
		curr->lch=t->rch;
		t->rch=curr;
		curr->maintain();
		t->maintain();
		curr=t;
}
void leftroute(Node *&curr){
    	Node *t=curr->rch;
		curr->rch=t->lch;
		t->lch=curr;
		curr->maintain();
		t->maintain();
		curr=t;
}
Node *ans=null;
void insert(Node *&curr,long long x){
    if(curr==null){
        curr=new Node();
		curr->lch=curr->rch=null;
        curr->x=x;
        curr->times=1;
        curr->maintain();
        return;
    }
    if(curr->x==x){
        curr->times++;
        curr->maintain();
        return;
    }
    if(x>curr->x){
        insert(curr->rch,x);
        if(curr->rch->pos<curr->pos) leftroute(curr);
    }else{
        insert(curr->lch,x);
        if(curr->lch->pos<curr->pos) rightroute(curr);
    }
    curr->maintain();
}
void del(Node *&curr,long long x){
    if(curr==null)return;
    if(curr->x==x){
        if (curr->times > 1){ 
            curr->times--;
            curr->maintain();
            return;
        }
        if(curr->lch==null){
            curr=curr->rch;
            return;
        }   
        if(curr->rch==null){
            curr=curr->lch;
            return;
        }
        if(curr->lch->pos<curr->rch->pos){
            rightroute(curr);
            del(curr->rch,x);
            curr->maintain();
            return;
        }else{
            leftroute(curr);
            del(curr->lch,x);
            curr->maintain();
            return;
        }
    }
    if(x<curr->x){
        del(curr->lch,x);
        curr->maintain();
        return;
    }else {
        del(curr->rch,x);
        curr->maintain();
        return;
    }
}
long long qurry(Node *curr,long long x){
    if(curr==null) return 0;
    if(curr->x==x){
        return curr->lch->sz+1;
    }
    if(x<curr->x){
        return qurry(curr->lch,x);
    }else{
    	return curr->lch->sz+curr->times+qurry(curr->rch,x);
    }
}
long long rankk(Node *curr,long long x){
    if(curr==null) return 0;
    if(x<=curr->lch->sz){
        return rankk(curr->lch,x);
    }else if(x>curr->lch->sz+curr->times){
        return rankk(curr->rch,x-curr->lch->sz-curr->times);
    }else{
        return curr->x;
    }
}
void pred(Node *curr,long long x){
    if (curr==null) return ;
    if (curr->x<x){
        ans=curr;
        pred(curr->rch,x);
    }else pred(curr->lch,x);
}

void succ(Node *curr,long long x){
    if (curr==null) return ;
    if (curr->x>x){
        ans=curr;
        succ(curr->lch,x);
    }else succ(curr->rch,x);
}
int main(){
	srand(time(0));
    long long n;
    scanf("%ld", &n);
    for (long long i=0;i<n;i++){
        long long x,y;
        ans=null;
        scanf("%ld%ld", &x,&y);
        switch(x){
            case 1:
                insert(root,y);
                break;
            case 2:
                del(root,y);
                break;
            case 3:
                printf("%d\n",qurry(root,y));
                break;
            case 4:
                printf("%d\n",rankk(root,y));
                break;
            case 5:
            	ans=null;
                pred(root,y);
                printf("%d\n",ans->x);
                break;
            case 6:
            	ans=null; 
                succ(root,y);
                printf("%d\n",ans->x);
                break;
        }
    }
}
