#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
const int maxn = 4000005;
const int INF = (1 << 31) - 1;
using namespace std;
int v[maxn], d[maxn], S, T;
vector<pair<int, int>> G[maxn];
void SPFA()
{
    queue<int> q;
    q.push(S);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < G[x].size(); i++)
        {
            int to = G[x][i].first;
            if (d[x] + G[x][i].second < d[to])
            {
                d[to] = d[x] + G[x][i].second;
                q.push(to);
            }
        }
    }
}
char map[2005][2005];
vector<int> trans[200];
int n, m;
int pos2num(int x, int y)
{
    return (x - 1) * m + y;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            map[i][j] = '#';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                S = pos2num(i, j);
            }
            if (map[i][j] == 'G')
            {
                T = pos2num(i, j);
            }
            if (map[i][j] >= 'a' && map[i][j] <= 'z')
            {
                trans[map[i][j]].push_back(pos2num(i, j));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] != '#')
            {
                if (map[i - 1][j] != '#')
                {
                    G[pos2num(i, j)].push_back(pair<int, int>(pos2num(i - 1, j), 1));
                }
                if (map[i + 1][j] != '#')
                {
                    G[pos2num(i, j)].push_back(pair<int, int>(pos2num(i + 1, j), 1));
                }
                if (map[i][j + 1] != '#')
                {
                    G[pos2num(i, j)].push_back(pair<int, int>(pos2num(i, j + 1), 1));
                }
                if (map[i][j - 1] != '#')
                {
                    G[pos2num(i, j)].push_back(pair<int, int>(pos2num(i, j - 1), 1));
                }
            }
        }
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (int i = 0; i < trans[c].size(); i++)
        {
            for (int j = 0; j < trans[c].size(); j++)
            {
                if (i == j)
                    continue;
                G[trans[c][i]].push_back(pair<int, int>(trans[c][j], 1));
            }
        }
    }
    for (int i = 0; i <= n * m; i++)
    {
        d[i] = INF;
    }
    d[S] = 0;
    SPFA();
    /*for (int i = 1; i <= n * m; i++)
    {
        cout << d[i] << endl;
    }*/
    if(d[T] == INF){
        cout << -1;
        return 0;
    }
    cout << d[T] << endl;
}