#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2000005;
struct LCA_ST
{
    int dep;
    int index;
    LCA_ST(int a = 0, int b = 0) : dep(a), index(b) {}
};
bool operator<(const LCA_ST &lhs, const LCA_ST &rhs)
{
    return lhs.dep < rhs.dep;
}
LCA_ST Stable[maxn][21];
struct ST
{
    void init(int a[], int index[], int n)
    {
        for (int i = 1; i <= n; i++)
        {
            Stable[i][0].dep = a[i];
            Stable[i][0].index = index[i];
        }
        for (int i = 1; (1 << i) <= n; i++)
            for (int j = 0; j + (1 << i) - 1 <= n; j++)
            {
                Stable[j][i] = min(Stable[j][i - 1], Stable[j + (1 << (i - 1))][i - 1]);
            }
    }
    LCA_ST search(int L, int R)
    {
        int k = 0;
        while ((1 << (k + 1)) <= R - L + 1)
            k++;
        return min(Stable[L][k], Stable[R - (1 << k) + 1][k]);
    }
};
ST st;
vector<int> G[maxn];
inline void addEdge(int from, int to)
{
    G[from].push_back(to);
    G[to].push_back(from);
}
int dd[maxn], ii[maxn], pos = 1;
int begin[maxn];
bool vis[maxn];
void dfs(int x, int dep)
{
    vis[x] = true;
    begin[x] = pos;
    dd[pos] = dep;
    ii[pos++] = x;
    for (int i = 0; i < G[x].size(); i++)
    {
        if (!vis[G[x][i]])
        {
            dfs(G[x][i], dep + 1);
            dd[pos] = dep;
            ii[pos++] = x;
        }
    }
}
int main()
{
    int n, m, root;
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 0; i < n-1; i++)
    {
        int ta, tb;
        scanf("%d%d", &ta, &tb);
        addEdge(ta, tb);
    }
    dfs(root,1);
    st.init(dd, ii, pos);
    for (int i = 0; i < m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int ta=begin[a],tb=begin[b];
        if(ta>tb) swap(ta,tb);
        printf("%d\n", st.search(ta,tb).index);
    }
}
