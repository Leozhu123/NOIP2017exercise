// luogu-judger-enable-o2
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int maxn = 200005;
const int inf = (1 << 30);
const int log_n = 25;
struct node
{
    int pos, h;
    node *pre, *nxt;
    bool operator<(const node &r) const
    {
        return h < r.h;
    }
};
node cities[maxn];
node *pos[maxn];
LL h[maxn];
LL nxt1[maxn], nxt2[maxn];
LL nxt3[maxn][log_n + 5], dp1[maxn][log_n + 5], dp2[maxn][log_n + 5];
LL h1[maxn], h2[maxn];
int n;
int x0, m;
void getdp(int &S, int len, LL &ans1, LL &ans2)
{
    int cnt = 0;
    while (len)
    {
        if (len & 1)
        {
            ans1 += dp1[S][cnt];
            ans2 += dp2[S][cnt];
            S = nxt3[S][cnt];
        }
        len >>= 1;
        cnt++;
        if (!S)
            break;
    }
    return;
}
int getmx(int S, LL x)
{
    int l = 0, mid, r = n + 1;
    while (r - l > 1)
    {
        mid = (l + r)/2;
        int nS = S;
        LL ans1 = 0, ans2 = 0;
        getdp(nS, mid, ans1, ans2);
        if (ans1 + ans2 > x || !nS)
            r = mid;
        else
            l = mid;
    }
    return l;
}
int LOG;
int main()
{
    cin >> n;
    int tmp=1;
    while(tmp<=n/3){
        LOG++;
        tmp <<= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cities[i].h;
        h[i] = cities[i].h;
        cities[i].pos = i;
        cities[i].pre = cities[i].nxt = 0;
    }
    sort(cities + 1, cities + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[cities[i].pos] = &cities[i];
        if (i - 1 >= 1)
            cities[i].pre = &cities[i - 1];
        if (i + 1 <= n)
            cities[i].nxt = &cities[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        pair<int, pair<int, int>> tmp[4];
        int cnt = 0;
        if (pos[i]->pre)
        {
            tmp[cnt++] = make_pair(abs(pos[i]->h - pos[i]->pre->h), make_pair(pos[i]->pre->h, pos[i]->pre->pos));
            if (pos[i]->pre->pre)
            {
                tmp[cnt++] = make_pair(abs(pos[i]->h - pos[i]->pre->pre->h), make_pair(pos[i]->pre->pre->h, pos[i]->pre->pre->pos));
            }
        }
        if (pos[i]->nxt)
        {
            tmp[cnt++] = make_pair(abs(pos[i]->h - pos[i]->nxt->h), make_pair(pos[i]->nxt->h, pos[i]->nxt->pos));
            if (pos[i]->nxt->nxt)
            {
                tmp[cnt++] = make_pair(abs(pos[i]->h - pos[i]->nxt->nxt->h), make_pair(pos[i]->nxt->nxt->h, pos[i]->nxt->nxt->pos));
            }
        }
        sort(tmp, tmp + cnt);
        if (cnt == 1)
        {
            nxt1[i] = tmp[0].second.second;
        }
        else if (cnt >= 2)
        {
            nxt1[i] = tmp[0].second.second;
            nxt2[i] = tmp[1].second.second;
        }
        if (pos[i]->pre)
            pos[i]->pre->nxt = pos[i]->nxt;
        if (pos[i]->nxt)
            pos[i]->nxt->pre = pos[i]->pre;
    }
    for (int i = 1; i < n; i++)
    {
        nxt3[i][0] = nxt1[nxt2[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        if (nxt1[i])
        {
            h1[i] = abs(h[nxt1[i]] - h[i]);
        }
        if (nxt2[i])
        {
            h2[i] = abs(h[nxt2[i]] - h[i]);
            dp2[i][0] = abs(h[nxt2[i]] - h[i]);
        }
        if (nxt1[nxt2[i]])
        {
            dp1[i][0] = abs(h[nxt1[nxt2[i]]] - h[nxt2[i]]);
        }
    }
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            nxt3[i][j] = nxt3[nxt3[i][j - 1]][j - 1];
            dp1[i][j] = dp1[i][j - 1] + dp1[nxt3[i][j - 1]][j - 1];
            dp2[i][j] = dp2[i][j - 1] + dp2[nxt3[i][j - 1]][j - 1];
          //  cout << nxt3[i][j] << " " << dp1[i][j] << " " << dp2[i][j] << endl;
        }
    }
    int mf1 = 0, mf2 = 1, mh = 0;
    int ans1 = 1;
    cin >> x0 >> m;
    for (int i = 1; i <= n; i++)
    {
        LL f1 = 0, f2 = 0;
        int nS = i;
        int mxl = getmx(i, x0);
        getdp(nS, mxl, f1, f2);
        if (nxt2[nS] && h2[nS] + f1 + f2 <= x0)
            f2 += h2[nS];
        if (!f2)
            continue;
        if (mf1 * f2 < f1 * mf2)
        {
            mf1 = f1;
            mf2 = f2;
            ans1 = i;
            mh = h[i];
        }
        else if (mf1 * f2 == mf2 * f1 && h[i] > mh)
        {
            mf1 = f1;
            mf2 = f2;
            ans1 = i;
            mh = h[i];
        }
     //   cout << "  " << ans1 << endl;
    }
    cout << ans1 << endl;
    for (int i = 1; i <= m; i++)
    {
        int Si, nSi;
        LL Xi;
        cin >> Si >> Xi;
        nSi = Si;
        int mxl = getmx(Si, Xi);
        LL f1 = 0, f2 = 0;
        getdp(nSi, mxl, f1, f2);
        if (nxt2[nSi] && h2[nSi] + f1 + f2 <= Xi)
            f2 += h2[nSi];
        cout << f2 << " " << f1 << endl;
    }
}