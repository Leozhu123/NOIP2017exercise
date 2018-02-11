#include <iostream>
#include <algorithm>
#include <climits>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

struct Woman {
    int Hkey, Wkey;
    explicit Woman(int h = 0, int w = 0)
        : Hkey(h), Wkey(w) {}
};

inline int LISLength(const std::vector<int>& seq) {
    std::vector<int> last;
    last.push_back(INT_MIN);
    last.push_back(seq.front());
    for (auto it = seq.begin() + 1; it != seq.end(); ++it) {
        auto pos = std::lower_bound(last.begin(), last.end(), *it);
        if (pos != last.end())
            *pos = *it;
        else
            last.push_back(*it);
    }
    return last.size() - 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    std::vector<Woman> women;
    for (int i = 0; i != n; ++i) {
        int h;
        cin >> h;
        women.push_back(Woman(h));
    }
    for (int i = 0; i != n; ++i) {
        int w; cin >> w;
        women[i].Wkey = w;
    }
    std::sort(women.begin(), women.end(),
              [](const Woman &w1, const Woman &w2) {
                  return w1.Hkey < w2.Hkey || (w1.Hkey == w2.Hkey && w1.Wkey > w2.Wkey);
              });
    std::vector<int> seq;
    for (const auto& w : women)
        seq.push_back(w.Wkey);
    cout << LISLength(seq) << endl;
    return 0;
}