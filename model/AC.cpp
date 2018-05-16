#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;
map<string, int> ms;
const int maxn = 2000005;
const int SIZE=30;
int ch[maxn][SIZE];
int val[maxn];
int f[maxn];
int n;
char P[200][80];
char T[maxn];
int cnt[maxn];
int tot = 1;
int last[maxn];
inline int idx(char c)
{
    return c - 'a';
}
void insert(char *P, int j)
{
    ms[string(P)] = j;
    int n = strlen(P);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int c = idx(P[i]);
        if (ch[k][c] == 0)
        {
        	for (int j=0;j<SIZE;j++){
				ch[tot][j]=0;
			}
        	val[tot]=0;
            ch[k][c] = tot++;
        }
        k = ch[k][c];
    }
    val[k] = j;
}
void getFail()
{
    queue<int> q;
    f[0] = 0;
    for (int i = 0; i < SIZE; i++)
    {
    	int u=ch[0][i];
        if (u)
        {
            f[u] = 0;
            q.push(u);
            last[u] = 0;
        }
    }
    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        for (int i = 0; i < SIZE; i++)
        {
            int u = ch[r][i];
            if (!u)
            {
            	ch[r][i]=ch[f[r]][i];
                continue;
            }
            q.push(u);
            int j = f[r];
            while (j && !ch[j][i])
            {
            	j=f[j];
            }
            f[u] = ch[j][i];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
        }
    }
}
void print(int x)
{
    if (x)
    {
        cnt[val[x]]++;
        print(last[x]);
    }
}
void match(char *T)
{
    int n = strlen(T);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int c = idx(T[i]);
        j = ch[j][c];
        if (val[j])
        {
            print(j);
        }
        else if (last[j])
        {
            print(last[j]);
        }
    }
}
void init(){
	tot=1;
	for (int i=0;i<SIZE;i++){
		ch[0][i]=0;
	}
	for (int i=0;i<maxn;i++){
		cnt[i]=0;
	}
	ms.clear();
}
int main()
{
	while (scanf("%d",&n)==1 && n){
    	init();
    	for (int i = 1; i <= n;i++){
        	scanf("%s",P[i]);
        	insert(P[i], i);
    	}
    	getFail();
    	scanf("%s", T);
    	match(T);
    	int best=-1;
    	for (int i = 1; i <= n;i++){
        	if (cnt[i]>best)
            	best = cnt[i];
    	}
    	printf("%d\n", best);
    	for (int i = 1; i <= n;i++){
        	if (cnt[ms[string(P[i])]]==best)
            	printf("%s\n", P[i]);
    	}
	}
}
