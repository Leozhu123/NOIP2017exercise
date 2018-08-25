// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <cctype>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <unordered_map>

template <typename T> inline void read(T& t) {
    int  f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
    read(t); read(args...);
}

#define rep(I, A, B) for (int  I = (A); I <= (B); ++I)
#define rrep(I, A, B) for (int  I = (A); I >= (B); --I)

struct Command {
    int  q, x, y, A, x1, y1, x2, y2;
};
Command cmd[170000 + 100];
int  xes[200100], yes[200100];
int  n, qcnt, xcnt, ycnt;
int  sum[80001000], left[80001000], right[80000100];
int  root[200100];
int  tot;
std::unordered_map<int, int> mpx, mpy;

void incSgt(int  &curr, int  l, int  r, int  pos, int  val) {
    if (!curr) curr = ++tot;
    sum[curr] += val;
    if (l == r) return;
    int  mid = (l + r) >> 1;
    if (pos <= mid)
        incSgt(left[curr], l, mid, pos, val);
    else
        incSgt(right[curr], mid + 1, r, pos, val);
}
int  querySgt(int  curr, int  lb, int  rb, int  l, int  r) {
    if (l > rb || r < lb) return 0;
    if (!curr) return 0;
    if (l <= lb && r >= rb) return sum[curr];
    int  mid = (lb + rb) >> 1;
    return querySgt(left[curr], lb, mid, l, r) + querySgt(right[curr], mid + 1, rb, l, r);
}

inline void incBit(int  x, int  y, int  val) {
    for (; x <= xcnt; x += x & -x)
        incSgt(root[x], 1, ycnt, y, val);
}
inline int  queryBit(int  x, int  y1, int  y2) {
    int  ans = 0;
    for (; x; x -= x & -x)
        ans += querySgt(root[x], 1, ycnt, y1, y2);
    return ans;
}

int main() {
    freopen("P4390.in", "r", stdin);
    freopen("P4390.out", "w", stdout);
    { int  zero; read(zero); }
    read(n);
    int  q;
    read(q);
    while (q != 3) {
        cmd[++qcnt].q = q;
        if (q == 1) {
            read(cmd[qcnt].x, cmd[qcnt].y, cmd[qcnt].A);
            xes[++xcnt] = cmd[qcnt].x;
            yes[++ycnt] = cmd[qcnt].y;
        }
        else {
            read(cmd[qcnt].x1, cmd[qcnt].y1, cmd[qcnt].x2, cmd[qcnt].y2);
            xes[++xcnt] = cmd[qcnt].x1;
            xes[++xcnt] = cmd[qcnt].x2;
            yes[++ycnt] = cmd[qcnt].y1;
            yes[++ycnt] = cmd[qcnt].y2;
        }
        read(q);
    }
    std::sort(xes + 1, xes + xcnt + 1);
    std::sort(yes + 1, yes + ycnt + 1);
    xcnt = std::unique(xes + 1, xes + xcnt + 1) - (xes + 1);
    ycnt = std::unique(yes + 1, yes + ycnt + 1) - (yes + 1);
    rep(i, 1, xcnt) mpx[xes[i]] = i;
    rep(i, 1, ycnt) mpy[yes[i]] = i;

    rep(i, 1, qcnt) {
        int  q = cmd[i].q;
        if (q == 1) {
            int  x = cmd[i].x, y = cmd[i].y, A = cmd[i].A;
            x = mpx[x], y = mpy[y];
            incBit(x, y, A);
        } else {
            int  x1 = cmd[i].x1, y1 = cmd[i].y1, x2 = cmd[i].x2, y2 = cmd[i].y2;
            x1 = mpx[x1], y1 = mpy[y1], x2 = mpx[x2], y2 = mpy[y2];
            int  ans = 0;
            ans += queryBit(x2, y1, y2);
            ans -= queryBit(x1 - 1, y1, y2);
            printf("%d\n", ans);
        }
    }
    return 0;
}