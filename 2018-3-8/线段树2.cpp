#include <iostream>
using namespace std;
long long mod = 0;
struct Node
{
    Node *lch, *rch;
    long long add, mul, sum, lc, rc;
    Node(long long l, long long r)
    {
        lc = l;
        rc = r;
        lch = rch = 0;
        sum = add = 0;
        mul = 1;
    }
    long long size()
    {
        return rc - lc + 1;
    }
    bool cover(long long l, long long r)
    {
        return l <= lc && r >= rc;
    }
    bool out(long long l, long long r)
    {
        return r < lc || l > rc;
    }
    void pushdown()
    {
        if (lch)
        {
            lch->add = (add + lch->add * mul) % mod;
            lch->mul = (lch->mul * mul) % mod;
            lch->sum = (lch->sum * mul + add * lch->size()) % mod;
        }
        if (rch)
        {
            rch->add = (add + rch->add * mul) % mod;
            rch->mul = (rch->mul * mul) % mod;
            rch->sum = (rch->sum * mul + add * rch->size()) % mod;
        }
        add = 0;
        mul = 1;
    }
    void getup()
    {
        sum = 0;
        if (lch)
        {
            sum += lch->sum;
        }
        if (rch)
        {
            sum += rch->sum;
        }
        sum = sum % mod;
    }
};
Node *root;
long long a[400000];
void build(Node *&curr, long long l, long long r)
{
    curr = new Node(l, r);
    if (l == r)
    {
        curr->sum = a[l] % mod;
        return;
    }
    long long mid = (l + r) >> 1;
    build(curr->lch, l, mid);
    build(curr->rch, mid + 1, r);
    curr->getup();
}
void modify(Node *curr, long long l, long long r, long long a, long long typ)
{
    curr->pushdown();
    if (curr->out(l, r))
        return;
    if (typ == 1 && curr->cover(l, r)) 
    {
        curr->mul = (curr->mul * a) % mod;
        curr->add = (curr->add * a) % mod;
        curr->sum = (curr->sum * curr->mul) % mod; 
        return;
    }
    if (typ == 2 && curr->cover(l, r))
    {
        curr->add = (curr->add + a) % mod;
        curr->sum = (curr->sum + curr->add * curr->size()) % mod;
        return;
    }
    if (curr->lch)
        modify(curr->lch, l, r, a, typ);
    if (curr->rch)
        modify(curr->rch, l, r, a, typ);
    curr->getup();
}
long long qurry(Node *curr, long long l, long long r)
{
    if (curr->out(l, r))
        return 0;
    if (curr->cover(l, r))
    {
        return curr->sum;
    }
    curr->pushdown();
    long long sum = 0;
    if (curr->lch)
        sum += qurry(curr->lch, l, r);
    if (curr->rch)
        sum += qurry(curr->rch, l, r);
    return sum % mod;
}
int main()
{
    long long n, m;
    cin >> n >> m >> mod;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(root, 1, n);
    for (long long i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        if (x == 1 || x == 2)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            modify(root, a, b, c, x);
        }
        else if (x == 3)
        {
            long long x, y;
            cin >> x >> y;
            cout << qurry(root, x, y) << endl;
        }
    }
}
