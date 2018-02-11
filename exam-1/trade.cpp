#include <cstdio>
#include <cstring>
const int maxn=10005;
int Graph[maxn][maxn],hv[maxn],ans[maxn],bans[maxn],n,m,i,j,k,v,n0,a,b,bt,w,aw;
bool vt[maxn];
void search(int nw,int lg)
{
	if(lg<=bt) return;
	if(vt[nw])
	{
		search(nw+1,lg);
		return;
	}
	if(nw==n+1)
	{
		bt=lg;
		memcpy(bans,ans,sizeof(ans));
		return;
	}
	for(int i=nw+1;i<=n;i++)
		if(i==n || !(vt[i] && Graph[nw][i]>=0))
		{
			ans[nw]=i,ans[i]=nw,vt[i]=true;
			search(nw+1,lg-hv[nw]-hv[i]+Graph[nw][i]);
			ans[nw]=0,ans[i]=0,vt[i]=false;
		}
}
int main()
{
	memset(Graph,0,sizeof(Graph));
	memset(vt,false,sizeof(vt));
	memset(bans,0,sizeof(bans));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&j,&k,&v);
		Graph[j][k]=v;
	}
	n++;
	for(i=1;i<=n-1;i++) Graph[i][n]=0;
	bt=0;
	for(i=1;i<=n-1;i++)
		if(!vt[i])
		{
			k=0;
			for(j=i+1;j<=n;j++) if(!vt[j] && (k==0 || Graph[i][j]>Graph[i][k])) k=j;
			if(k!=0 && Graph[i][k]>=0) bt+=Graph[i][k],bans[i]=k,bans[k]=i,vt[k]=true;
		}
	memset(vt,false,sizeof(vt));
	memset(ans,0,sizeof(ans));
	search(1,aw);
	printf("%d\n",bt);
	return 0;
}
