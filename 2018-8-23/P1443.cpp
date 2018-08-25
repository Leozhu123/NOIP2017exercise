#include<bits/stdc++.h>    
#define P pair<int,int>
using namespace std;
const int addx[8] = {1,2,2,1,-1,-2,-2,-1};
const int addy[8] = {2,1,-1,-2,2,1,-1,-2};
int dis[500][500];
queue<P> q;
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            dis[i][j] = -1;
        }
    }
    dis[x][y]=0;
    q.push(P(x,y));
    while(!q.empty()){
        P curr=q.front();
        q.pop();
        for (int i = 0; i < 8;i++){
            int tx=curr.first+addx[i];
            int ty = curr.second + addy[i];
            if(dis[tx][ty]!=-1)
                continue;
            dis[tx][ty] = dis[curr.first][curr.second] + 1;
            q.push(P(tx, ty));
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cout<<left<<setw(5)<<dis[i][j];
        }
        printf("\n");
    }
}