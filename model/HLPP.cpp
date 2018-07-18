#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
const int maxn = 15;
const int INF = (1 << 31) - 1;
using namespace std;
struct Edge
{
    int from, to, cap, flow;
    Edge(int from, int to, int cap)
    {
        this->from = from;
        this->to = to;
        this->cap = cap;
        this->flow = 0;
    }
};
struct HLPP
{
    vector<Edge> edges;
    vector<int> G[maxn];
    void addEdge(int from, int to, int cap)
    {
        Edge e1(from, to, cap), e2(to, from, 0);
        edges.push_back(e1);
        edges.push_back(e2);
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    int s, t, n, h[maxn], flowin[maxn], flowout[maxn];
    int MaxFlow(int s, int t, int n)
    {
        this->s = s;
        this->t = t;
        this->n = n;
        memset(h, 0, sizeof(h));
        memset(flowin, 0, sizeof(flowin));
        memset(flowout, 0, sizeof(flowout));
        h[s] = n;
        priority_queue<pair<int, int>> q;
        for (int x : G[s])
        {
            Edge &e = edges[x];
            // if (e.from == x)
            {
                flowout[s] += e.cap;
                flowin[e.to] += e.cap;
                e.flow = e.cap;
                edges[x ^ 1].flow -= e.cap;
                q.push(pair<int, int>(h[e.to], e.to));
            }
        }
        cout << flowout[s] << endl;
        while (!q.empty())
        {
            pair<int, int> now = q.top();
            q.pop();
            for (int x : G[now.second])
            {
                Edge &e = edges[x];
                if (h[e.to] == h[now.second] - 1)
                {
                    int flow = min(e.cap - e.flow, flowin[now.second] - flowout[now.second]);
                    if (flow > 0)
                    {
                        e.flow += flow;
                        flowout[now.second] += flow;
                        flowin[e.to] += flow;
                        edges[x ^ 1].flow -= flow;
                        q.push(pair<int, int>(h[e.to], e.to));
                    }
                }
            }
            if (flowin[now.second] > flowout[now.second])
            {
                int nh = n;
                for (int x : G[now.second])
                {
                    if (edges[x].cap > edges[x].flow)
                    {
                        nh = min(nh, h[edges[x].to]);
                    }
                }
                h[now.second] = nh + 1;
                q.push(pair<int, int>(h[now.second], now.second));
            }
        }
        int ans = 0;
        for (int x : G[s])
        {
            Edge &e = edges[x];
            if (e.from == s)
            {
                ans += e.flow;
            }
        }
        return ans;
    }
};
int main()
{
    int n, m, s, t;
    HLPP maxflow;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        maxflow.addEdge(a, b, c);
    }
    cout << maxflow.MaxFlow(s, t, n);
}
