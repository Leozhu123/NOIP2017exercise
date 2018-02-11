#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
struct Node{
    int v[3],dist;
    bool operator < (const Node &r) const {
        return dist>r.dist;
    }
};
int ans[1000],cap[3];
void update_ans(const Node &u){
    for (int i=0;i<3;i++){
        int d=u.v[i];
        if (ans[d]<0 || u.dist<ans[d]) ans[d]=u.dist;
    }
}    
bool vis[1000][1000];
void solve(int a,int b,int c,int d){
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    cap[0]=a;cap[1]=b;cap[2]=c;
    Node start;
    start.dist=0;
    start.v[0]=0;start.v[1]=0;start.v[2]=c;
    priority_queue<Node> q;
    vis[0][0]=true;
    q.push(start);
    while (!q.empty()){
        Node u=q.top();
        q.pop();
        update_ans(u);
        if (ans[d]>=0) break;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (i!=j){
                    if (u.v[i]==0|| u.v[j]==cap[j]) continue;
                    int amount=min(cap[j],u.v[i]+u.v[j])-u.v[j];
                    Node u2;
                    u2.dist=u.dist+amount;
                    u2.v[1]=u.v[1];u2.v[2]=u.v[2];u2.v[0]=u.v[0];
                    u2.v[i]-=amount;
                    u2.v[j]+=amount;
                    if (!vis[u2.v[0]][u2.v[1]]) {
                        vis[u2.v[0]][u2.v[1]]=true;
                        q.push(u2);
                    }
                }
            }
        }
	}
    while (d>=0){
        if (ans[d]>=0){
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }  
		   
}
int main(){
    int T,a,b,c,d;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
    return 0;
}    

