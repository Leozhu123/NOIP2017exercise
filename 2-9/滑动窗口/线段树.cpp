#include <iostream>
#include <climits>
#define int long long
using std::cin;
using std::cout;
using std::endl;
using namespace std;
inline long long max(long long a, long long b ){
    return a > b ? a : b;
} 
inline long long min(long long a, long long b ){
    return a < b ? a : b;
} 
struct Node
{
    int lb = 0, rb = 0;
    int max =0,min =0;
    int lc = 0, rc = 0;
    explicit Node(int l, int r)
        : lb(l), rb(r) {}
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

Node segtree[200010];
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

inline void getup(Node& curr) {
    curr.min = min(left(curr).min , right(curr).min);
    curr.max = max(left(curr).max , right(curr).max);

}

inline void build(Node& curr, int l, int r) {
    curr = Node(l, r);
    if (curr.unique()) {
        curr.max =curr.min = a[l];
        return;
    }
    curr.lc = ++segend;
    curr.rc = ++segend;
    int mid = (l + r) >> 1;
    build(left(curr), l, mid);
    build(right(curr), mid + 1, r);
    getup(curr);
}

inline int querymin(Node& curr, int l, int r) {
    if (curr.out(l, r))
        return 0;
    if (curr.covered(l, r))
        return curr.min;
    return min(querymin(left(curr), l, r) , querymin(right(curr), l, r));
}
inline int querymax(Node& curr, int l, int r) {
    if (curr.out(l, r))
        return 0;
    if (curr.covered(l, r))
        return curr.max;
    return max(querymax(left(curr), l, r) , querymax(right(curr), l, r));
}

#undef int

int main() {
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        scanf("%d", a[i]);
    }
    build(root, 1, n);
    for (int i=0;i<=n-k;i++){
		printf("%d ",querymin(root,i,i+k-1));
	}
	printf("\n");
	for (int i = 0; i <= n - k; i++)
	{
		printf("%d ",querymax(root,i,i+k-1));
	}
        return 0;
}