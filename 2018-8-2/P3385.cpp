#include <cctype>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>

template <typename T> inline void read(T& t) {
    int f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
    read(t);
    read(args...);
}

#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 3e3 + 100;
typedef int arrT[maxn << 1];
arrT v, w, head, next, dist;
int n, m, tot;

inline void ae(int x, int y, int z) {
    v[++tot] = y;
    w[tot] = z;
    next[tot] = head[x];
    head[x] = tot;
}
inline void init() {
    rep(i, 1, n) { head[i] = 0, dist[i] = INT_MAX; }
    rep(i, 0, (m << 1))
        v[i] = w[i] = next[i] = 0;
    tot = 0;
}
inline bool spfa(int s) {
    std::queue<int> q;
    q.push(s);
    dist[s] = 0;
    arrT intimes = {0};
    ++intimes[s];
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = next[i])
            if (dist[v[i]] > dist[x] + w[i]) {
                dist[v[i]] = dist[x] + w[i];
                q.push(v[i]);
                intimes[v[i]] = intimes[x] + 1;
                if (intimes[v[i]] >= n)
                    return 0;
            }
    }
    return 1;
}

int main() {
    int T;
    read(T);
    while (T--) {
        read(n, m);
        init();
        rep(i, 1, m) {
            int x, y, z;
            read(x, y, z);
            ae(x, y, z);
            if (z >= 0)
                ae(y, x, z);
        }
        if (spfa(1)) puts("N0");
        else puts("YE5");
    }
    return 0;
}