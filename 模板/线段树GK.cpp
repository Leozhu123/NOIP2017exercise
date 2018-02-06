#include <iostream>
#include <algorithm>
#include <climits>
#define int long long
using std::cin;
using std::cout;
using std::endl;

struct Node {
    int lb = 0, rb = 0;
    int sum = 0, delta = 0;
    int lc = 0, rc = 0;
    explicit Node(int l, int r, int s)
        : lb(l), rb(r), sum(s) {}
    Node() = default;
    int size() const { return rb - lb + 1; }
    bool unique() const { return lb == rb; }
    bool out(int l, int r) const {
        return l > rb || r < lb;
    }
    bool covered(int l, int r ) const {
        return l <= lb && r >= rb;
    }
};

Node segtree[400010];
Node &root = segtree[1];
int segend = 1;
int a[100010];
int n, m;

inline Node& left(const Node& curr) {
    return segtree[curr.lc];
}
inline Node& right(const Node& curr) {
    return segtree[curr.rc];
}

inline void pushdown(Node& curr) {
    if (curr.delta) {
        left(curr).sum += left(curr).size() * curr.delta;
        right(curr).sum += right(curr).size() * curr.delta;
        left(curr).delta += curr.delta;
        right(curr).delta += curr.delta;
        curr.delta = 0;
    }
}

inline void getup(Node& curr) {
    curr.sum = left(curr).sum + right(curr).sum;
}

inline void build(Node& curr, int l, int r) {
    curr = Node(l, r, 0);
    if (curr.unique()) {
        curr.sum = a[l];
        return;
    }
    curr.lc = ++segend;
    curr.rc = ++segend;
    int mid = (l + r) >> 1;
    build(left(curr), l, mid);
    build(right(curr), mid + 1, r);
    getup(curr);
}

inline void modify(Node& curr, int l, int r, int d) {
    if (curr.out(l, r))
        return;
    if (curr.covered(l, r)) {
        curr.sum += curr.size() * d;
        curr.delta += d;
        return;
    }
    pushdown(curr);
    modify(left(curr), l, r, d);
    modify(right(curr), l, r, d);
    getup(curr);
}

inline int querySum(Node& curr, int l, int r) {
    if (curr.out(l, r))
        return 0;
    if (curr.covered(l, r))
        return curr.sum;
    pushdown(curr);
    return querySum(left(curr), l, r) + querySum(right(curr), l, r);
}

#undef int

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(root, 1, n);
    while (m--) {
        int q;
        cin >> q;
        int x, y;
        cin >> x >> y;
        if (q == 1) {
            int d;
            cin >> d;
            modify(root, x, y, d);
        } else {
            cout << querySum(root, x, y) << endl;
        }
    }
    return 0;
}