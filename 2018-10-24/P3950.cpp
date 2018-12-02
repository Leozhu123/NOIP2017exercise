#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define LL long long
#define P pair<int,int>
using namespace std;
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
const long long maxn = 300005;
long long da[maxn];
struct SplayNode
{
	SplayNode *lch, *rch, *father, *path_parent;
	long long idx, xo;
	bool isRev;
	SplayNode(long long idx)
	{
		lch = rch = father = path_parent = 0;
		isRev = false;
		xo = 0;
		this->idx = idx;
	}
	inline void update()
	{
		xo = 0;
		if (lch)
			xo ^= lch->xo;
		if (rch)
			xo ^= rch->xo;
		xo = xo ^ da[idx];
	}
	inline void pushdown()
	{
		if (isRev)
		{
			if (rch)
				rch->isRev = !rch->isRev;
			if (lch)
				lch->isRev = !lch->isRev;
			isRev = false;
			SplayNode *t = lch;
			lch = rch;
			rch = t;
		}
		update();
	}
	inline void leftroute()
	{
		SplayNode *y = father;
		path_parent = y->path_parent;
		y->path_parent = 0;
		y->rch = lch;
		if (lch)
		{
			lch->father = y;
		}
		father = y->father;
		if (y->father)
		{
			if (y == y->father->lch)
				y->father->lch = this;
			else
				y->father->rch = this;
		}
		y->father = this;
		lch = y;
		y->update();
		update();
	}
	inline void rightroute()
	{
		SplayNode *y = father;
		path_parent = y->path_parent;
		y->path_parent = 0;
		y->lch = rch;
		if (rch)
		{
			rch->father = y;
		}
		father = y->father;
		if (y->father)
		{
			if (y == y->father->lch)
				y->father->lch = this;
			else
				y->father->rch = this;
		}
		y->father = this;
		rch = y;
		y->update();
		update();
	}
	inline void rev()
	{
		isRev = !isRev;
		pushdown();
	}
};
SplayNode *location[maxn];
inline void splay(SplayNode *x)
{
	while (x->father)
	{
		SplayNode *father = x->father;
		x->father->pushdown();
		if (father->lch)
			father->lch->pushdown();
		if (father->rch)
			father->rch->pushdown();
		if (x == x->father->lch)
		{
			x->rightroute();
		}
		else
		{
			x->leftroute();
		}
	}
}
inline void Access(SplayNode *p)
{
	splay(p);
	p->pushdown();
	SplayNode *q = p->rch;
	if (q)
	{
		p->rch = q->father = 0;
		p->update();
		q->path_parent = p;
	}
	p->pushdown();
	for (q = p->path_parent; q; q = p->path_parent)
	{
		splay(q);
		splay(p);
		q->pushdown();
		SplayNode *r = q->rch;
		q->rch = p;
		q->update();
		q->father = 0;
		if (r)
		{
			r->path_parent = q;
			r->father = 0;
		}
		p->father = q;
		p->path_parent = 0;
		p = q;
	}
	splay(p);
}
inline SplayNode *FindRoot(SplayNode *p)
{
	Access(p);
	splay(p);
	p->pushdown();
	while (p && p->lch)
	{
		p = p->lch;
		p->pushdown();
	}
	splay(p);
	p->pushdown();
	return p;
}
inline void Evert(SplayNode *p)
{
	Access(p);
	splay(p);
	p->rev();
	p->pushdown();
}
inline void Cut(SplayNode *p, SplayNode *q)
{
	Evert(p);
	Access(q);
	splay(q);
	q->pushdown();
	if (q->lch==p)
		q->lch->father = 0;
	q->lch = 0;
	q->update();
}
inline void Link(SplayNode *p, SplayNode *q)
{
	Evert(p);
	splay(p);
	p->pushdown();
	Access(q);
	splay(q);
	q->pushdown();
	p->lch = q;
	p->update();
	q->father = p;
	q->path_parent = 0;
	p->pushdown();
}
inline void MakeTree(long long idx)
{
	SplayNode *p = new SplayNode(idx);
	location[idx] = p;
	p->xo = da[idx];
}
inline long long ask(SplayNode *p, SplayNode *q)
{
	Evert(p);
	splay(p);
	p->pushdown();
	Access(q);
	splay(q);
	q->pushdown();
	return q->xo;
}
inline void change(long long idx, long long x)
{
	da[idx] = x;
	SplayNode *cur = location[idx];
	splay(cur);
	cur->update();
}
int n, m;
int u[maxn], v[maxn];
int cnt = 1;
int main()
{
    read(n,m);
    for(int i=1;i<=n;i++){
        MakeTree(i);
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        read(u, v);
        Link(location[u], location[v]);
    }
	for (long long i = 0; i < m; i++)
	{
        char str[5];
        long long a, b;
        scanf("%s%lld", str, &a);
        if (str[0]=='Q')
		{
            read(b);
            printf("%s\n", FindRoot(location[a]) == FindRoot(location[b]) ? "Yes" : "No");
        }
		else if (str[0]=='C')
		{
            read(b);
            Cut(location[a], location[b]);
            u[cnt]=a;
            v[cnt]=b;
            cnt++;
        }
		else{
            Link(location[u[a]], location[v[a]]);
        }
	}
}
