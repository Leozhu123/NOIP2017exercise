#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
using namespace std;
const int maxn = 160;
const double INF = 1e20;
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
struct Point
{
    int x, y;
    double distance(const Point &b)
    {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
};
int n;
int field[maxn];
double diameter[maxn];
double dist[maxn][maxn];
void dfs(int i, int id)
{
    field[i] = id;
    for (int j = 0; j < n; j++)
    {
        if (!field[j] && dist[i][j] < INF)
            dfs(j, id);
    }
}
Point a[maxn];
char s[maxn];
double max_sp[maxn];
int main()
{
    read(n);
    for (int i = 0; i < n; i++)
    {
        read(a[i].x, a[i].y);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '1' || i == j)
                dist[i][j] = a[i].distance(a[j]);
            else
                dist[i][j] = INF;
        }
    }
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        if (!field[i])
            dfs(i, ++id);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    for (int i = 0; i<n; i++)
    {
        max_sp[i] = 0;
        for (int j = 0; j < n; ++j)
            if (dist[i][j] < INF)
                max_sp[i] = max(max_sp[i], dist[i][j]);
        diameter[field[i]] = max(diameter[field[i]], max_sp[i]);
    }
    double min_d = INF, max_d;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (field[i] != field[j])
            {
                max_d = max(max(diameter[field[i]], diameter[field[j]]),
                            max_sp[i] + a[i].distance(a[j]) + max_sp[j]);
                min_d = min(min_d, max_d);
            }

    printf("%.6f\n", min_d);
}