#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200000;
int father[maxn];
long long ans[maxn];
struct Edge
{
    int from, to;
    long long data;
    Edge(int f, int t, int d) : from(f), to(t), data(d) {}
};
vector<Edge> G[maxn];
void dfs(int x)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        if (G[x][i].to != father[x])
        {
            ans[G[x][i].to] = ans[x] ^ G[x][i].data;
            father[G[x][i].to] = x;
            dfs(G[x][i].to);
        }
    }
}
int n, m;
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge e1(a, b, c), e2(b, a, c);
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
    ans[1] = 0;
    dfs(1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (ans[a] ^ ans[b]) << endl;
    }
}
