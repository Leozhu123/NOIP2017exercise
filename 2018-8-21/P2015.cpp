#include <iostream>
#include <algorithm>
#include <climits>

using std::cin;
using std::cout;
using std::endl;

typedef int arrT[500];
arrT v, w, head, next, fa;
int n, m, total;
int dp[500][500];

inline void add_edge(int x, int y, int z) {
    v[++total] = y;
    w[total] = z;
    next[total] = head[x];
    head[x] = total;
}

void dfs(int x) {
    dp[x][0] = 0;
    for (int i = head[x]; i; i = next[i])
        if (v[i] != fa[x]) {
            fa[v[i]] = x;
            dfs(v[i]);
            for (int j = m; j >= 1; --j)
                for (int k = 0; k < j; ++k)
                    dp[x][j] = std::max(dp[x][j], dp[x][k] + dp[v[i]][j - k - 1] + w[i]);
        }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i) {
        int x, y, z; cin >> x >> y >> z;
        add_edge(x, y, z);
        add_edge(y, x, z);
    }
    dfs(1);
    cout << dp[1][m] << endl;
    return 0;
}