#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
const int INF=1000000;
bool map[100][100][100];
int d[100][100][100];
struct point{
  int x,y,z;
};
int x,y,z,sx,sy,sz,ex,ey,ez;
int add_z[6]={0,0,0,0,1,-1};
int add_x[6]={1,-1,0,0,0,0};
int add_y[6]={0,0,1,-1,0,0};
using namespace std;
void init(){
  for (int i=0;i<100;i++)
      for (int j=0;j<100;j++)
        for (int k=0;k<100;k++){ 
          map[i][j][k]=false;
          d[i][j][k]=INF;
        }
}  
int bfs(int sz,int sx,int sy){
  queue<point> q1;
  point tmp;
  tmp.x=sx;
  tmp.y=sy;
  tmp.z=sz;
  int nx,ny,nz;
  d[sz][sx][sy]=0;
  q1.push(tmp);
  while (!q1.empty()){
    point t;
    t=q1.front();
    q1.pop();
    nx=t.x;
    ny=t.y;
    nz=t.z;
    for (int i=0;i<6;i++){
      if (nz+add_z[i]>=0 
	    && nx+add_x[i]>=0 
		&& ny+add_y[i]>=0 
		&& map[nz+add_z[i]][nx+add_x[i]][ny+add_y[i]] 
		&& d[nz+add_z[i]][nx+add_x[i]][ny+add_y[i]]>=d[nz][nx][ny]+1) {
        point tmp;
        tmp.x=nx+add_x[i];
        tmp.y=ny+add_y[i];
        tmp.z=nz+add_z[i];
        d[tmp.z][tmp.x][tmp.y]=d[nz][nx][ny]+1;
        q1.push(tmp);
      }  
    }
  }
  if (d[ez][ex][ey]==INF) return -1; else return d[ez][ex][ey];
}
int main(){
  while (scanf("%d%d%d",&z,&x,&y)){
    init();
    if (z==0 && x==0 &&y==0) break;
    for (int i=0;i<z;i++)
      for (int j=0;j<x;j++)
        for (int k=0;k<y;k++){
          char ch;
          scanf("%c",&ch);
          while (!(ch=='S' || ch=='.' || ch=='#' || ch=='E'))
            scanf("%c",&ch);
          if (ch=='S') {
            sz=i;
            sx=j;
            sy=k;
            map[i][j][k]=true;
          }
          if (ch=='E') {
            ez=i;
            ex=j;
            ey=k;
            map[i][j][k]=true;
          }
          if (ch=='.') map[i][j][k]=true;
        } 
     int ans=bfs(sz,sx,sy);
     if (ans>0)
       printf("Escaped in %d minute(s).\n",ans);
     else printf("Trapped!\n");
     }
}
  

