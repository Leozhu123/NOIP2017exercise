#include <cstdio>
#include <vector>
using namespace std;
struct data{
    int v,num;
};
const int maxn=500005,INF=(1<<31)-1;
bool vis[maxn];
int p[maxn],sp[maxn],n,m,root,ancestor[maxn];
vector<int> G[maxn],que;
vector<data> q[maxn];
int find_set(int x){
    return x==sp[x]?sp[x]:sp[x]=find_set(sp[x]);
}   
inline int union_set(int x,int y){
    int px=find_set(x),py=find_set(y);
        sp[px]=py;
}
inline int read()
{
    int ee=0,ff=1;
    char ss=getchar();
    while((ss<'0'||ss>'9')&&ss!='-')ss=getchar();
    while((ss>='0'&&ss<='9')||ss=='-')
    {
        if(ss=='-')ff=-1;
        else ee=ee*10+ss-'0';
        ss=getchar();
    }
    return ee*ff;
}
void DFS(int x){
	int a=G[x].size();
    for (int i=0;i<a;i++){
        if (G[x][i]==p[x]) continue;
		p[G[x][i]]=x;
        DFS(G[x][i]);
        union_set(x,G[x][i]);
		vis[G[x][i]]=true;
        ancestor[find_set(x)]=x;
    }
    a=q[x].size();
    for (int i=0;i<a;i++){
        if (vis[q[x][i].v] )que[q[x][i].num]=ancestor[find_set(q[x][i].v)];
    }    
}  
int main(){
  n=read();
  m=read();
  root=read();
  sp[0]=0;
  for (int i=0;i<n-1;i++){
    int u,v;
    sp[i+1]=i+1;
    u=read();
    v=read();
    G[u].push_back(v);
    G[v].push_back(u);
  }  
  for (int i=0;i<m;i++){
  	  int u,v;  
      u=read();
      v=read();
      que.push_back(0);
	  data t,t2;
	  t.v=v;
	  t.num=t2.num=que.size()-1;
      q[u].push_back(t);
	  t2.v=u;
      q[v].push_back(t2);
  }  
  DFS(root);
  int a=que.size();
  for (int i=0;i<a;i++)
      printf("%d\n",que[i]);
}  
