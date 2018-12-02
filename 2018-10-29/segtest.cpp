const int max=1e5;
struct Node{
    int x,delta;
    Node *lch,*rch;
    Node(){
        x=delta=0;
        lch = rch = 0;
    }
    void pushdwn(int l,int r){
        int mid=(l+r)>>1;
        lch->x+=delta*(mid-l+1);
        rch->x+=delta*(r-mid);
        lch->delta+=delta;
        rch->delta+=delta;
        delta = 0;
    }
    void update(){
        x = lch->x + rch->x;
    }
};
void build(NOde *&curr,int l,int r){
    curr = new Node();
    if (l == r)
    {
        curr->x = a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(curr->lch,l,mid);
    build(curr->rch,mid+1,r);
    curr->update();
}
void modify(Node *curr,int l,int r,int ml,int mr,int x){
    if(ml<=l &&r<=mr){
        curr->x+=x*(r-l+1);
        curr->delta+=delta;
        return;
    }
    int mid=(l+r)>>1;
    curr->pushdown();
    if(l<=mid) modify(curr->lch,l,mid,ml,ml,x);
    if(r>=mid+1)modify(curr->rch,mid+1,r,ml,mr,x);
    curr->update();
}
int query(Node *curr,int l,int r,int ml,int mr){
    if(ml<=l &&r<=mr){
        return curr->x;
    }
    int mid=(l+r)>>1;
    curr->pushdown();
    int ans = 0;
    if(l<=mid) ans+=query(curr->lch,l,mid,ml,ml);
    if(r>=mid+1)ans+=query(curr->rch,mid+1,r,ml,mr);
    return ans;
}