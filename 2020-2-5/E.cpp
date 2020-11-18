/*
	  author : evenbao
	  created :
*/
#include<bits/stdc++.h>

using namespace std;

#ifndef LOCAL
	  #define eprintf(...) fprintf(stderr , _VA_ARGS)
#else
	  #define eprintf(...) 42
#endif

// define evenbao
#define PII pair<int , int>
#define FI first
#define SE second
#define MP make_pair

typedef long long LL;

const int N = 5e5 + 10;
const int MAXLOG = 20;

int n;
int father[N][MAXLOG] , depth[N];
vector< int > E[N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}

inline void DFS(int u , int fa) {
		father[u][0] = fa;
		depth[u] = depth[fa] + 1;
		for (int i = 1; i < MAXLOG; ++i)
				father[u][i] = father[father[u][i - 1]][i - 1];
		for (auto v : E[u]) {
				if (v == fa) continue;
				DFS(v , u);
		}
}
inline int LCA(int x , int y) {
		if (depth[x] > depth[y]) swap(x , y);
		for (int i = MAXLOG - 1; i >= 0; --i)
				if (depth[father[y][i]] >= depth[x])
						y = father[y][i];
		if (x == y) return x;
		for (int i = MAXLOG - 1; i >= 0; --i) {
				if (father[x][i] != father[y][i])
						x = father[x][i] , y = father[y][i];
		}
		return father[x][0];
}
inline int calc(int x , int y) {
		return depth[x] + depth[y] - 2 * depth[LCA(x , y)];
}

int main() {
		
		read(n);
		for (int i = 1; i < n; ++i) {
				int u , v;
				read(u) , read(v);
				E[u].push_back(v);
				E[v].push_back(u);
		}
		DFS(1 , 0);
		int q; read(q);
		while (q--) {
				int x , y , a , b , k;
				read(x) , read(y) , read(a) , read(b) , read(k);
				/***** case 1 *****/
				int dis = calc(a , b);
				if (dis <= k && (dis & 1) == (k & 1)) {
						printf("YES\n");
						continue;
				}
				/***** case 2 *****/
				    dis = min(1 + calc(a , x) + calc(b , y) , 1 + calc(a , y) + calc(b , x));
				if (dis <= k && (dis & 1) == (k & 1)) {
						printf("YES\n");
						continue;
				}
				printf("NO\n");
		}
		
	  return 0;
}