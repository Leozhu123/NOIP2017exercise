#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
		#define eprintf(...) fprintf(stderr, _VA_ARGS_)
#else
		#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<ll , ll> pll;
typedef long double ld;
typedef vector< int > vi;
typedef unsigned long long ull;
#define mp make_pair
#define fi first
#define se second
const int N = 1.5e5 + 10;
const int M = 1.5e6 + 10;
const int INF = 2e9;

int n , m , sz , w , h , Rt;
int dist[M] , X[N] , Y[N] , L[N] , R[N] , U[N] , D[N] , pos[N] , t[N] , lc[M] , rc[M] , rt[M];
vector< pii > e[M];
map< pii , int > cnt;

template <typename T> inline void chkmax(T &x,T y) { x = max(x,y); }
template <typename T> inline void chkmin(T &x,T y) { x = min(x,y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}
template <typename T> inline void write(T x) {
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
}
template <typename T> inline void writeln(T x) {
		write(x);
		puts("");
}
inline void addedge(int u , int v , int w) {
		e[u].push_back(mp(v , w));
}
inline void modifyC(int &now , int l , int r , int x , int S) {
		if (!now) now = ++sz;
		if (l == r) {
				addedge(now , S , 0);
				return;
		} 
		int mid = (l + r) >> 1;
		if (mid >= x) modifyC(lc[now] , l , mid , x , S);
		else modifyC(rc[now] , mid + 1 , r , x , S);
		if (lc[now]) addedge(now , lc[now] , 0);
		if (rc[now]) addedge(now , rc[now] , 0);
}
inline void modifyR(int &now , int l , int r , int X , int Y , int S) {
		if (!now) now = ++sz;
		modifyC(rt[now] , 1 , h , Y , S);
		if (l == r) return;
		else {
				int mid = (l + r) >> 1;
				if (mid >= X) modifyR(lc[now] , l , mid , X , Y , S);
				else modifyR(rc[now] , mid + 1 , r , X , Y , S);
		}
}
inline void LinkC(int now , int l , int r , int ql , int qr , int S , int W) {
		if (!now) return;
		if (l == ql && r == qr) {
				addedge(S , now , W);
				return;
		} else {
				int mid = (l + r) >> 1;
				if (mid >= qr) LinkC(lc[now] , l , mid , ql , qr , S , W);
				else if (mid + 1 <= ql) LinkC(rc[now] , mid + 1 , r , ql , qr , S , W);
				else {
						LinkC(lc[now] , l , mid , ql , mid , S , W);
						LinkC(rc[now] , mid + 1 , r , mid + 1 , qr , S , W);
				}
		}
}
inline void LinkR(int now , int l , int r , int ql , int qr , int qu , int qd , int S , int W) {
		if (!now) return;
		if (l == ql && r == qr) {
				LinkC(rt[now] , 1 , h , qu , qd , S , W);
				return;
		}	else {
				int mid = (l + r) >> 1;
				if (mid >= qr) LinkR(lc[now] , l , mid , ql , qr , qu , qd , S , W);
				else if (mid + 1 <= ql) LinkR(rc[now] , mid + 1 , r , ql , qr , qu , qd , S , W);
				else {
						LinkR(lc[now] , l , mid , ql , mid , qu , qd , S , W);
						LinkR(rc[now] , mid + 1 , r , mid + 1 , qr , qu , qd , S , W);
				}
		}
}

inline void dijkstra(int s) {
		priority_queue< pii , vector< pii > , greater< pii > > q;
		static bool visited[M];
		for (int i = 1; i <= sz; ++i) {
				visited[i] = false;
				dist[i] = INF;
		}
		q.push(mp(0 , s));
		dist[s] = 0;
		while (!q.empty()) {
				int cur = q.top().se; q.pop();
				if (visited[cur]) continue;
				visited[cur] = true;
				for (unsigned i = 0; i < e[cur].size(); ++i) {
						int v = e[cur][i].fi , w = e[cur][i].se;
						if (dist[cur] + w < dist[v]) {
								dist[v] = dist[cur] + w;
								q.push(mp(dist[v] , v));
						}
				}
		}
}

int main() {
		
		#ifndef evenbao
		freopen("jump.in" , "r" , stdin);
		freopen("jump.out" , "w" , stdout);
		#endif
		
		read(n); read(m); read(w); read(h);
		for (int i = 1; i <= n; ++i) {
				read(X[i]);
				read(Y[i]);		
				++cnt[mp(X[i] , Y[i])];
		}
		bool tag = true;
		for (int i = 1; i <= m; ++i) {
				read(pos[i]);
				read(t[i]);
				read(L[i]);
				read(R[i]);
				read(D[i]);
				read(U[i]);
				addedge(pos[i] , i + n , 0);
				tag &= (L[i] == R[i] && D[i] == U[i] && cnt[mp(L[i] , D[i])] == 1);
		}
		sz = n + m;
		if (tag) {
				map< pii , int > id;
				id.clear();
				for (int i = 1; i <= n; ++i)
						id[mp(X[i] , Y[i])] = i;
				for (int i = 1; i <= m; ++i)
						addedge(i + n , id[mp(L[i] , D[i])] , t[i]);
		} else {
				for (int i = 1; i <= n; ++i)
						modifyR(Rt , 1 , w , X[i] , Y[i] , i);
				for (int i = 1; i <= m; ++i) 
						LinkR(Rt , 1 , w , L[i] , R[i] , D[i] , U[i] , i + n , t[i]);
		} 
		dijkstra(1);
		for (int i = 2; i <= n; ++i)
				writeln(dist[i]);
				
		return 0; 
	
}

