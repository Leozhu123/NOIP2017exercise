#include <iostream>
#include <cstdio>
#include <queue>
#define P pair<int,int>

const int addx[4]={1,-1,1,-1};
const int addy[4]={1,1,-1,-1};

int board[2005][2005];
int ans[2005][2005];
using namespace std;

P start,ed;

int main(){
    queue<P > q;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char ch;
            cin>>ch;
            if(ch=='#')
                board[i][j] = 1;
            else if(ch=='m')
                start = P(i, j);
            else if(ch=='d')
                ed = P(i, j);
        }
    }
    cout << start.first<<" "<<start.second << endl;
    q.push(start);
    while(!q.empty()){
        P x=q.front();
        if(x==ed){
            cout<<ans[ed.first][ed.second];
            return 0;
        }
        for(int i=0;i<4;i++){
            P nxt=P(x.first+addx[i],x.second+addy[i]);
            if(board[nxt.first][nxt.second]==0 && ans[nxt.first][nxt.second]==0){
                q.push(nxt);
                ans[nxt.first][nxt.second] = ans[x.first][x.second] + 1;
                
            }
        }
    }
    cout << "No Way!";
}