#include <cstdio>
#include <iostream>
#include <queue>
#define P pair<int, int>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = (1 << 31) - 1;
vector<P> G[maxn];
priority_queue<P, vector<P >, greater<P > > q;
int d[maxn];
int n, m, S;
void ae(int a,int b,int v){
    G[a].push_back(P(b, v));
    G[b].push_back(P(a, v));
}
void dji()
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[S] = 0;
    q.push(P(d[S], S));
    while (!q.empty())
    {
        P x = q.top();
        q.pop();
        if (x.first > d[x.second])
            continue;
        int u = x.second;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i].first;
            if (d[v] > d[u] + G[u][i].second)
            {
                d[v] = d[u] + G[u][i].second;
                q.push(P(d[v], v));
            }
        }
    }
}
int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    n = 200;
    for (int i = 1; i <= 99;i++){
        ae(i, i + 1, y);
        ae(i + 100, i + 101, y);
        ae(i + 1, i + 100, x);
    }
    for (int i = 1;i<=n;i++){
        ae(i, i + 100, x);
    }
    S = a;
    dji();
    cout << d[100 + b];
}