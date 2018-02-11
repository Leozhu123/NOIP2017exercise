#include <iostream>
#include <algorithm>
#include <climits>
#include <map>

using std::cin;
using std::cout;
using std::endl;

int G[200][200];
int n;
std::map<int, int> dp;

inline int dfs(int used) {
    if (dp.count(used) )
        return dp[used];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (used & (1 << i))
            continue;
        for (int j = 1; j <= n; ++j) {
            if (!(used & (1 << j)))
                ans = std::max(ans, dfs(used | (1 << j)) + G[i][j]);
        }
    }
    return memo[used] = ans;
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> G[i][j];
        dp.clear();
        dp[(1 << (n + 1)) - 1] = 0;
        cout << dfs(0) << endl;
    }
    return 0;
}
