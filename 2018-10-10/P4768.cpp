#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#define PAS system("pause")
#define CHK  //printf("run to %s at line %d\n",__FUNCTION__,__LINE__)
#define P pair<int,int>
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
using namespace std;
#define LL long long
const int maxn = 200010;
LL dis[maxn];
struct LongTimeArray{
	private:
	int size=0;
	struct Node
	{
    	LL x;
    	Node *lch, *rch;
    	Node()
    	{
        	x = 0;
        	lch = rch = 0;
    	}
	};
	void build(Node *&curr, int l, int r,vector<int> &a)
	{
    	curr = new Node();
    	if (l == r)
    	{
        	curr->x = a[l];
        	return;
    	}
    	int mid = (l + r) >> 1;
    	build(curr->lch, l, mid,a);
    	build(curr->rch, mid + 1, r,a);
	}
	vector <Node*> root;
	void update(Node *&curr, Node *pre, int l, int r, int pos, int x)
	{
    	curr = new Node();
    	if (l == r)
    	{
        	curr->x = x;
        	return;
    	}
    	int mid = (l + r) >> 1;
    	if (pos <= mid)
    	{
        	curr->rch = pre->rch;
        	update(curr->lch, pre->lch, l, mid, pos, x);
    	}
    	else
    	{
        	curr->lch = pre->lch;
        	update(curr->rch, pre->rch, mid + 1, r, pos, x);
    	}
	}
	Node * qurry(Node *curr, int l, int r, int pos)
	{
    	CHK;
    	if (l == r)
        	return curr;
    	int mid = (l + r) >> 1;
    	if (pos<=mid)
        	return qurry(curr->lch, l, mid, pos);
    	else
        	return qurry(curr->rch, mid + 1, r, pos);
	}
	public:
	LongTimeArray(vector<int> &a){
		root.push_back(0);
		build(root[0],0,a.size()-1,a);
		size=a.size()-1;
	}
	int modify(int pre,int pos,int x){
		root.push_back(root[pre]);
		update(root[root.size()-1],root[pre],0,size,pos,x);
		return root.size()-1;
	}
	LL qurry(int pre,int pos){
		return qurry(root[pre],0,size,pos)->x;
	}
};
struct Node
{
    LL fa, deep, dist;
    Node *lch, *rch;
    Node()
    {
        fa = deep = dist = 0;
        lch = rch = 0;
    }
};
Node *root[maxn];
void build(Node *&curr, int l, int r)
{
    curr = new Node();
    if (l == r)
    {
        curr->fa = l;
        curr->dist = dis[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(curr->lch, l, mid);
    build(curr->rch, mid + 1, r);
}
void update(Node *&curr, Node *pre, int l, int r, int pos, int ff)
{
    curr = new Node();
    if (l == r)
    {
        curr->fa = ff;
        curr->deep = pre->deep;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        curr->rch = pre->rch;
        update(curr->lch, pre->lch, l, mid, pos, ff);
    }
    else
    {
        curr->lch = pre->lch;
        update(curr->rch, pre->rch, mid + 1, r, pos, ff);
    }
}
Node *qurry(Node *curr, int l, int r, int pos)
{
    if (l == r)
        return curr;
    int mid = (l + r) >> 1;
    if (pos<=mid)
        return qurry(curr->lch, l, mid, pos);
    else
        return qurry(curr->rch, mid + 1, r, pos);
}
int n, m;
void add(Node *curr, int l, int r, int pos)
{
    if (l == r)
    {
        curr->deep++;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        add(curr->lch, l, mid, pos);
    else
        add(curr->rch, mid + 1, r, pos);
}
Node *find_fa(Node *ed, int x)
{
    Node *ff = qurry(ed, 1, n, x);
    if (x == ff->fa)
        return ff;
    else
        return find_fa(ed, ff->fa);
}
struct Edge{
    int u, v, l, h;
    Edge(int u,int v,int l,int h):u(u),v(v),l(l),h(h){}
};
priority_queue<P , vector<P> , greater<P> > q;
vector<Edge> G[maxn];
vector<Edge> edges;
vector<P> num;
void init(){
    for (int i = 0; i <= n;i++){
        G[i].clear();
        dis[i] = INT_MAX;
        root[i] = 0;
    }
    num.clear();
    edges.clear();
}
bool cmp(const Edge &l,const Edge &r){
    return l.h > r.h;
}
void Dij(){
    dis[1]=0;
    q.push(P(0, 1));
    while(!q.empty()){
        P x=q.top();
        q.pop();
        if(x.first>dis[x.second])
            continue;
        int u=x.second;
        for (int i = 0; i < G[u].size();i++){
            Edge &e = G[u][i];
            if(dis[e.v]>dis[u]+e.l){
                dis[e.v]=dis[u]+e.l;
                q.push(P(dis[e.v], e.v));
            }
        }
    }
}
int main()
{
    int T;
    read(T);
    while(T--){
        read(n, m);
        init();
        for (int i = 1;i<= m; i++){
            int u,v,l,a;
            read(u, v, l, a);
            edges.push_back(Edge(u, v, l, a));
            G[u].push_back(Edge(u, v, l, a));
            G[v].push_back(Edge(v, u, l, a));
        }
        Dij();
        vector<int> a;
        a.push_back(0);
        for(int i=1;i<=n;i++)
            a.push_back(dis[i]);
        LongTimeArray dist(a);
        sort(edges.begin(), edges.end(), cmp);
        int Q, K, S;
        int lastans = 0;
        read(Q, K, S);
        build(root[0], 1, n);
        num.push_back(P(0,m));
        root[1]=root[0];
        for (int i = 1;i<=m;i++){
            Edge &e = edges[i-1];
            if((i<m && e.h>edges[i].h) || i==m){
                num.push_back(P(e.h, i));
            }
            root[i] = root[i- 1];
            Node *f1 = find_fa(root[i], e.u);
            Node *f2 = find_fa(root[i], e.v);
            if (f1->fa == f2->fa)
                continue;
            if (f1->deep > f2->deep)
                swap(f1, f2);
            update(root[i], root[i - 1], 1, n, f1->fa, f2->fa);
            if (f1->deep == f2->deep)
                add(root[i], 1, n, f2->fa);
            dist.modify(i - 1, f2->fa, min(dist.qurry(i - 1, f1->fa), dist.qurry(i - 1, f2->fa)));
        }
        sort(num.begin(),num.end());
        for (int i = 1;i<=Q;i++){
            int v,p;
            read(v,p);
            v = (v + K * lastans - 1) % n + 1;
            p = (p + K * lastans) % (S + 1);
            p++;
            auto pos = upper_bound(num.begin(), num.end(), P(p, 0)) ;
            if(pos->first<p)
                pos++;
            cout<<pos->second<<endl;
            Node * fa=find_fa(root[pos->second],p);
            cout<<fa->fa<<endl;
			printf("%lld\n", dist.qurry(pos->second,fa->fa));
        }
    }
}
