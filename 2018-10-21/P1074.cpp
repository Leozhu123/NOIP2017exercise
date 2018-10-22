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
#define P pair<int,pair<int,int> >
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
int suduku[10][10];
int canput[10][10][4];//1为行，2为列，3为九宫格
int score[10][10];
int cont[15];
int cnt = 0;
int ans = 0;
int mxans = 0;
int calcone(int x){
    int ans = 0;
    while(x){
        if(x&1) ans++;
        x >>= 1;
    }
    return ans;
}
void mark(int x,int y,int a){
    cnt++;
    cont[score[x][y]]++;
    ans += score[x][y] * a;
    suduku[x][y]=a;
    for (int i = 1; i <= 9;i++){
        canput[i][y][1] |= (1 << (a - 1));
    }
    for(int i=1;i<=9;i++){
        canput[x][i][2] |= (1 << (a - 1));
    }
    for(int i=((x-1)/3)*3+1;i<=((x-1)/3)*3+3;i++){
        for(int j=((y-1)/3)*3+1;j<=((y-1)/3)*3+3;j++){
            canput[i][j][3] |= (1 << (a - 1));
        }
    }
}
void unmark(int x,int y,int a){
    cnt--;
    cont[score[x][y]]--;
    ans -= score[x][y] * a;
    suduku[x][y]=0;
    for (int i = 1; i <= 9;i++){
        canput[i][y][1] &= ~(1 << (a - 1));
    }
    for(int i=1;i<=9;i++){
        canput[x][i][2] &= ~(1 << (a - 1));
    }
    for(int i=((x-1)/3)*3+1;i<=((x-1)/3)*3+3;i++){
        for(int j=((y-1)/3)*3+1;j<=((y-1)/3)*3+3;j++){
            canput[i][j][3] &= ~(1 << (a - 1));
        }
    }
}
void dfs(int x,int y,int a){
    mark(x,y,a);
    if(cnt==81){
        mxans=max(ans,mxans);
    }else{
        vector<P> choices;
        for (int i = 1;i<=9;i++){
            for(int j=1;j<=9;j++){
                int choice = canput[i][j][1] | canput[i][j][2] | canput[i][j][3];
                if(suduku[i][j]==0){
                    choices.push_back(make_pair(9 - calcone(choice), make_pair(i, j)));
                }
            }
        }
        sort(choices.begin(),choices.end());
        for(int i=0;i<choices.size();i++){
            int x=choices[i].second.first;
            int y=choices[i].second.second;
            int choice = canput[x][y][1] | canput[x][y][2] | canput[x][y][3];
            for(int j=1;j<=9;j++){
                if(!((choice)&(1<<(j-1)))){
                    dfs(x, y, j);
                }
            }   
        }
    }
    unmark(x, y, a);
}
int main(){
    for(int i=1;i<=9;i++)
        for (int j = 1; j <= 9;j++)
            score[i][j] = 6;
    for(int i=2;i<=8;i++)
        for (int j = 2; j <= 8;j++)
            score[i][j] = 7;
    for(int i=3;i<=7;i++)
        for (int j = 3; j <= 7;j++)
            score[i][j] = 8;
    for(int i=4;i<=6;i++)
        for (int j = 4; j <= 6;j++)
            score[i][j] = 9;
    score[5][5] = 10;
    for(int i=1;i<=9;i++){
        for (int j = 1;j<=9;j++){
            int x;
            read(x);
            if(x>0){
                mark(i, j, x);
            }
        }
    }
    vector<P> choices;
    for (int i = 1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int choice = canput[i][j][1] | canput[i][j][2] | canput[i][j][3];
            if(suduku[i][j]==0){
                choices.push_back(make_pair(9 - calcone(choice), make_pair(i, j)));
            }
        }
    }
    sort(choices.begin(),choices.end());
    for(int i=0;i<choices.size();i++){
        int x=choices[i].second.first;
        int y=choices[i].second.second;
        int choice = canput[x][y][1] | canput[x][y][2] | canput[x][y][3];
        for(int j=1;j<=9;j++){
            if(!((choice)&(1<<(j-1)))){
                dfs(x, y, j);
            }
        }
    }
    cout << mxans;
}
