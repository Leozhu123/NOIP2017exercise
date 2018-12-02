#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define LL long long
#define P pair<int, int>
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
const int N = 10;
int n, map[N][N], ans[N][5], last[N][N][N], xiao[N][N];
bool remove()
{
    bool flag = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (i - 1 >= 1 && i + 1 <= 5 && map[i][j] == map[i - 1][j] && map[i][j] == map[i + 1][j] && map[i][j])
            {
                xiao[i - 1][j] = 1;
                xiao[i + 1][j] = 1;
                xiao[i][j] = 1;
                flag = 1;
            }
            if (j - 1 >= 1 && j + 1 <= 7 && map[i][j] == map[i][j + 1] && map[i][j] == map[i][j - 1] && map[i][j])
            {
                xiao[i][j] = 1;
                xiao[i][j + 1] = 1;
                xiao[i][j - 1] = 1;
                flag = 1;
            }
        }
    }
    if(!flag) return 0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=7;j++){
            if(xiao[i][j]){
                xiao[i][j]=0;
                map[i][j] = 0;
            }
        }
    }
    return 1;
}
bool check(){
    for(int i=1;i<=5;i++)
        if(map[i][1]) return 0;
    return 1;
}
void copy(int x){
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
            last[x][i][j] = map[i][j];
}
void update(){
    for(int i=1;i<=5;i++){
        int wow = 0;
        for(int j=1;j<=7;j++){
            if(!map[i][j])
                wow++;
            else{
                if(!wow)
                    continue;
                map[i][j - wow] = map[i][j];
                map[i][j] = 0;
            }
        }
    }
}
void move(int i,int j,int x){
    int tmp=map[i][j];
    map[i][j] = map[i + x][j];
    map[i+x][j]=tmp;
    update();
    while(remove())
        update();
}
void dfs(int x){
    if(check()){
        for(int i=1;i<=n;i++){
            if(i!=1)
                printf("\n");
            for(int j=1;j<=3;j++)
                printf("%d ", ans[i][j]);
        }
        exit(0);
    }
    if(x==n+1) return;
    copy(x);
    for(int i=1;i<=5;i++){
        for(int j=1;j<=7;j++){
            if(map[i][j]){
                if(i+1<=5 && map[i][j]!=map[i+1][j]){
                    move(i, j, 1);
                    ans[x][1] = i - 1;
                    ans[x][2]=j-1;
                    ans[x][3] = 1;
                    dfs(x+1);
                    for(int i=1;i<=5;i++)
                        for (int j = 1;j<=7;j++)
                            map[i][j] = last[x][i][j];
                    ans[x][1] = ans[x][2] = ans[x][3] = -1;
                }
                if(i-1>=1 && map[i-1][j]==0){
                    move(i,j,-1);
                    ans[x][1]=i-1;
                    ans[x][2] = j - 1;
                    ans[x][3] = -1;
                    dfs(x + 1);
                    for(int i=1;i<=5;i++)
                        for (int j = 1;j<=7;j++)
                            map[i][j] = last[x][i][j];
                    ans[x][1] = ans[x][2] = ans[x][3] = -1;    
                }
            }
        }
    }
}
int main(){
    read(n);
    for(int i=1;i<=5;i++)
        for(int j=1;j<=8;j++){
            int x;
            read(x);
            if(x==0)
                break;
            map[i][j] = x;
        }
    memset(ans,-1,sizeof(ans));
    dfs(1);
    puts("-1");
}