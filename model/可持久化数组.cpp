#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
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
const int maxn = 2000010;
vector<int> a;
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
		root.push_back(root[pre]);
		return qurry(root[root.size()-1],0,size,pos)->x;
	}
};
int n, m;
int main()
{
    read(n, m);
    CHK;
    for (int i = 1; i <= n;i++){
        int x;
        read(x);
        a.push_back(x);
    }
    LongTimeArray array(a);
    for (int i = 1; i <= m; i++)
    {
        int opt;
        int vi;
        read(vi);
        read(opt);
        if (opt == 1)
        {
            int pos,v;
            read(pos, v);
            array.modify(vi,pos-1,v);
        }
        if (opt == 2)
        {
            int k;
            read(k);
            printf("%lld\n", array.qurry(vi,k-1));
        }
    }
}
