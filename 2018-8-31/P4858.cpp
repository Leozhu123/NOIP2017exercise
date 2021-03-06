#include <cstdio>
#include <iostream>
using namespace std;
const long long maxn = 1005;
long long da[maxn];
struct SplayNode
{
	SplayNode *lch, *rch, *father, *path_parent;
	long long idx, sum;
	bool isRev;
	SplayNode(long long idx)
	{
		lch = rch = father = path_parent = 0;
		isRev = false;
		sum = 0;
		this->idx = idx;
	}
	inline void update()
	{
		sum = 0;
		if (lch)
			sum += lch->sum;
		if (rch)
			sum += rch->sum;
		sum = sum + da[idx];
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
	p->sum = da[idx];
}
inline long long ask(SplayNode *p, SplayNode *q)
{
	Evert(p);
	splay(p);
	p->pushdown();
	Access(q);
	splay(q);
	q->pushdown();
	return q->sum;
}
inline void change(long long idx, long long x)
{
	da[idx] = x;
	SplayNode *cur = location[idx];
	splay(cur);
	cur->update();
}
int main()
{
	long long n, m;
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &da[i]);
		MakeTree(i);
	}
    scanf("%lld", &m);
    for (long long i = 0; i < m; i++)
	{
		long long a, b;
		char str[100];
        scanf("%s%lld%lld",str,&a,&b);
        switch(str[0]){
            case 'b':
                if(FindRoot(location[a])==FindRoot(location[b])){
                    puts("no");
                }else{
                    puts("yes");
                    Link(location[a], location[b]);
                }
                break;
            case 'p':
                change(a,b);
                break;
            case 'e':
                if(FindRoot(location[a])==FindRoot(location[b])){
                    printf("%lld\n", ask(location[a], location[b]));
                }else{
                    puts("impossible");
                }
        }
	}
}
