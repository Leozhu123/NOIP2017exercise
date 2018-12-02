#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
const int M = 50005 ;
const int N = 20 ;
using namespace std;
inline int read(){
    int x=0,w=1; char c=getchar(); 
    while(c>'9'||c<'0'){ if(c=='-') w=-1 ;c=getchar() ;}
    while(c>='0'&&c<='9'){ x=x*10+c-'0'; c=getchar() ; }
    return x*w;
}
int hea[M],num;
int n,m;
int p[M];
int st[M][N],f[M][N],Ans;
int top[M],tdis[M];
int rnum=0;
int q[M],tail=0;
bool lea[M];
bool vis[M];
bool fs=0;
struct E{
    int nex,to;
    int dis;
}edge[M<<2];
struct Army{
    int Rest;
    int Top;
}army[M];
inline bool cmp(int a,int b){ return a>b; }
inline bool cmpmin(Army a,Army b){ return a.Rest<b.Rest; }
inline bool cmpmax(Army a,Army b){ return a.Rest>b.Rest; }
inline void add_edge(int from,int to,int dis){
    edge[++num].nex=hea[from];
    edge[num].to=to;
    edge[num].dis=dis;
    hea[from]=num;
}
void Dfs(int u,int father){
    for(int i=hea[u];i;i=edge[i].nex){
        int v=edge[i].to;
        if(v==father) continue ;
        f[v][0]=u; 
        st[v][0]=edge[i].dis;
        Dfs(v,u);
    }
}
void RMQ(){
    for(int j=1;j<=18;j++)
      for(int i=1;i<=n;i++){
        f[i][j]=f[f[i][j-1]][j-1];
        st[i][j]=st[i][j-1]+st[f[i][j-1]][j-1];
      }
}
void Dfs1(int u,int father,int topf,int dist){
    top[u]=topf;
    tdis[u]=dist;
    bool ft=0;
    for(int i=hea[u];i;i=edge[i].nex){
        int v=edge[i].to;
        if(v==father) continue ;
        ft=1;
        Dfs1(v,u,topf,dist);
    }
    if(!ft)  lea[u]=1;
}
void Dfs2(int u,int father){
    if(lea[u]){
        fs=1;
        return ;
    }
    for(int i=hea[u];i;i=edge[i].nex){
        int v=edge[i].to;
        if(v==father) continue ;
        else if(vis[v]) continue ;
        Dfs2(v,u);
        if(fs) return ;
    }
}
inline bool Look(int v){
    fs=0;
    Dfs2(v,f[v][0]);
    return fs;
}
inline bool judge(int mid){
    memset(vis,0,sizeof(vis));
    memset(q,0,sizeof(q));
    memset(army,0,sizeof(army));
    rnum=0;
    tail=0;
    for(int i=1;i<=m;i++){
        int tim=mid;
        int now=p[i];
        bool syst=0;
        while(1){
            for(int j=18;j>=0;j--){
              if(f[now][j]&&st[now][j]<=tim){
                tim-=st[now][j];
                now=f[now][j];
                break;
              }
              if(j==0||now==1){
                syst=1;
                break;
              }
            }
            if(syst) break;
        }
        if(now==1){
            army[++rnum].Top=top[p[i]];
            army[rnum].Rest=tim;
        }
        else vis[now]=1;
    }   
    sort(army+1,army+m+1,cmpmin);
    for(int i=1;i<=m;i++) 
      if(army[i].Rest<tdis[army[i].Top]){
        if(!vis[army[i].Top]&&Look(army[i].Top)){
            vis[army[i].Top]=1;
            army[i].Rest=-1;
        }
      }
    sort(army+1,army+m+1,cmpmax);
    for(int i=hea[1];i;i=edge[i].nex){
        int v=edge[i].to;
        if(!vis[v]&&Look(v))
          q[++tail]=edge[i].dis;
    }
    sort(q+1,q+tail+1,cmp);
    for(int i=1;i<=tail;i++)
      if(army[i].Rest<q[i])
        return false;
    return true; 
}
int main(){
    n=read();
    int R=0;
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        int w = read();
        add_edge(u,v,w);
        add_edge(v,u,w);
        R+=w;
    }
    Dfs(1,0);
    for(int i=hea[1];i;i=edge[i].nex){
        int v=edge[i].to;
        Dfs1(v,1,v,edge[i].dis);
    }
    RMQ();
    m=read();
    for(int i=1;i<=m;i++) p[i]=read();
    int tmp=0;
    for(int i=hea[1];i;i=edge[i].nex) tmp++;
    if(tmp>m){
        printf("-1\n");
        return 0;
    }
    int L=0;
    while(L<=R){
        int mid=(L+R)>>1;
        if(judge(mid)) Ans=mid,R=mid-1;
        else L=mid+1;
    }
    printf("%d\n",Ans);
    return 0;
}
