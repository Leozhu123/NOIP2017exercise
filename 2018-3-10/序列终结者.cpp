#include <iostream>
using namespace std;
const int maxn = 50005;
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
	void update()
	{
		xo = 0;
		if (lch)
			xo ^= lch->xo;
		if (rch)
			xo ^= rch->xo;
		xo = xo ^ da[idx];
	}
	void pushdown()
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
	void leftroute()
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
	void rightroute()
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
	void rev()
	{
		isRev = !isRev;
		pushdown();
	}
};
SplayNode *location[maxn];
void splay(SplayNode *x)
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
int main(){
    
}