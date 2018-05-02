#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2000005;
vector<int> G[maxn];
inline void addEdge(int from, int to)
{
    G[from].push_back(to);
    G[to].push_back(from);
}
int fa[maxn][22];
int dep[maxn];
void dfs(int x, int depth,int father)
{
    dep[x]=depth;
    fa[x][0]=father;
    for (int i=1;i<=20;i++){
        if (fa[x][i-1])
            fa[x][i]=fa[fa[x][i-1]][i-1];
        else break; 
    }
    for (int i = 0; i < G[x].size(); i++)
    {
        if (G[x][i]!=father)
        {
            dfs(G[x][i], depth + 1,x);
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
    dfs(root,1,0);
    for (int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if (dep[a]<dep[b]){
            int tmp=a;
            a=b;
            b=tmp;
        }
        int delta=dep[a]-dep[b];
        for (int i=0;i<=20;i++){
            if(delta&(1<<i))
                a=fa[a][i];
        }
        if(a==b){
            printf("%d\n",a);
            continue;
        }
        for (int i=20;i>=0;i--){
            if(fa[a][i]!=fa[b][i]){
                a=fa[a][i];
                b=fa[b][i];
            }
        }
        printf("%d\n",fa[a][0]);
    }
}
