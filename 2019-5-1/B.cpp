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
#include <stack>
#include <vector>
#include <string>
#include <sstream>
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
int T;
const int maxn = 105;
char str[maxn];
vector<int> G[maxn];
int cnt = 0;
bool vis[maxn];
string ans;
bool isn(char a,char b){
    if(a > b) swap(a,b);
    return b == a + 1;
}
void dfs(int x){
    cout << x << endl;
    ans.push_back(str[x]);
    for (int i = 0; i < G[x].size();i++){
        if(!vis[G[x][i]]){
            cnt++;
            vis[G[x][i]] = true;
            dfs(G[x][i]);
            break;
        }
    }
}
int main(){
    read(T);
    while(T--){
        scanf("%s", str + 1);
        int n = strlen(str + 1);
        for (int i = 1;i<=n;i++){
            for (int j = i + 1;j<=n;j++){
                if(!isn(str[i],str[j])){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        cnt++;
        vis[1] = true;
        dfs(1);
        if(cnt != n){
            puts("No answer");
        }else{
            cout << ans << endl;
        }
        memset(vis,0,sizeof(vis));
        for (int i = 1;i<=n;i++){
            G[i].clear();
        }
        ans = "";
        cnt = 0;
    }
}