//by ciwomuli
//enter ICPC WF 2020
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define LL long long
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
struct Node
{
    long long x;
    long long sz;
    long long times;
    Node *lch, *rch;
    long long pos;
    Node()
    {
        x = sz = times = 0;
        lch = rch = 0;
        pos = rand();
    }
    void maintain()
    {
        sz = times + lch->sz + rch->sz;
    }
};
Node *null = new Node();
Node *root = null;
void rightroute(Node *&curr)
{
    Node *t = curr->lch;
    curr->lch = t->rch;
    t->rch = curr;
    curr->maintain();
    t->maintain();
    curr = t;
}
void leftroute(Node *&curr)
{
    Node *t = curr->rch;
    curr->rch = t->lch;
    t->lch = curr;
    curr->maintain();
    t->maintain();
    curr = t;
}
Node *ans = null;
void insert(Node *&curr, long long x)
{
    if (curr == null)
    {
        curr = new Node();
        curr->lch = curr->rch = null;
        curr->x = x;
        curr->times = 1;
        curr->maintain();
        return;
    }
    if (curr->x == x)
    {
        curr->times++;
        curr->maintain();
        return;
    }
    if (x > curr->x)
    {
        insert(curr->rch, x);
        if (curr->rch->pos < curr->pos)
            leftroute(curr);
    }
    else
    {
        insert(curr->lch, x);
        if (curr->lch->pos < curr->pos)
            rightroute(curr);
    }
    curr->maintain();
}
void del(Node *&curr, long long x)
{
    if (curr == null)
        return;
    if (curr->x == x)
    {
        if (curr->times > 1)
        {
            curr->times--;
            curr->maintain();
            return;
        }
        if (curr->lch == null)
        {
            curr = curr->rch;
            return;
        }
        if (curr->rch == null)
        {
            curr = curr->lch;
            return;
        }
        if (curr->lch->pos < curr->rch->pos)
        {
            rightroute(curr);
            del(curr->rch, x);
            curr->maintain();
            return;
        }
        else
        {
            leftroute(curr);
            del(curr->lch, x);
            curr->maintain();
            return;
        }
    }
    if (x < curr->x)
    {
        del(curr->lch, x);
        curr->maintain();
        return;
    }
    else
    {
        del(curr->rch, x);
        curr->maintain();
        return;
    }
}
long long query(Node *curr, long long x)
{
    if (curr == null)
        return 0;
    if (curr->x == x)
    {
        return curr->lch->sz + 1;
    }
    if (x < curr->x)
    {
        return query(curr->lch, x);
    }
    else
    {
        return curr->lch->sz + curr->times + query(curr->rch, x);
    }
}
long long rankk(Node *curr, long long x)
{
    if (curr == null)
        return 0;
    if (x <= curr->lch->sz)
    {
        return rankk(curr->lch, x);
    }
    else if (x > curr->lch->sz + curr->times)
    {
        return rankk(curr->rch, x - curr->lch->sz - curr->times);
    }
    else
    {
        return curr->x;
    }
}
void pred(Node *curr, long long x)
{
    if (curr == null)
        return;
    if (curr->x < x)
    {
        ans = curr;
        pred(curr->rch, x);
    }
    else
        pred(curr->lch, x);
}

void succ(Node *curr, long long x)
{
    if (curr == null)
        return;
    if (curr->x > x)
    {
        ans = curr;
        succ(curr->lch, x);
    }
    else
        succ(curr->rch, x);
}
set<LL> s;
LL n, m;
LL op, pos;
bool check(LL x)
{
    if (!s.count(x))
        return true;
    if (query(root, x) - query(root, pos) < x - pos)
        return true;
    return false;
}
LL ef()
{
    if (!s.count(pos))
        return pos;
    if (!check(n))
        return -1;
    LL l = pos, r = n;
    while (r - l > 5)
    {
        LL mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    for (int i = l; i <= r; i++)
    {
        if (check(i))
        {
            return i;
        }
    }
}
int main()
{
    srand(time(0));
    read(n, m);
    for (int i = 1; i <= m; i++)
    {
        read(op, pos);
        if (op == 1)
        {
            if (s.count(pos))
                continue;
            insert(root, pos);
            s.insert(pos);
        }
        else
        {
            cout << ef() << endl;
        }
    }
}