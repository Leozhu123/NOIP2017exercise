//by ciwomuli
//AK JSOI 2019
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define LL long long
using namespace std;
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
const int maxn = 100005;
int fa[maxn];
int c[maxn];
int cnt[maxn];
vector<int> G[maxn];
vector<int> vec;
void dfs(int x, int f){
    for (int i = 0; i < G[x].size();i++){
        int v=G[x][i];
        if(c[v]==0)
            cnt[x]++;
        dfs(v, x);
    }
    if(c[x]==1 && cnt[x] == 0)
        vec.push_back(x);
}
int main()
{
    int n;
    read(n);
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        read(x, y);
        if (x == -1)
            root = i, c[i] = y;
        else
            fa[i] = x, c[i] = y , G[x].push_back(i);
    }
    dfs(root, 0);
    sort(vec.begin(), vec.end());
    bool ok = false;
    for(auto i:vec){
        cout << i << " ";
        ok = true;
    }
    if(!ok)
        puts("-1");
}