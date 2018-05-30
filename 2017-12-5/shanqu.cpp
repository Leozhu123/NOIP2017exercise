#include<cstdio>
#include<cstdlib>
#include<cstring>

const int N=510,M=510;
int a[N],s[N],f[N][M],dis[N][N];

int mmin(int x,int y) {return x<y?x:y;}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    s[1]=0;
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];//计算从1到i的距离和
    }
    for (int l=1;l<=n;l++)
        for (int r=l;r<=n;r++)
        {
            int mid=(l+r)>>1;
            dis[l][r]=0;
            for (int k=l;k<mid;k++)//计算[l,r]内每个点到中间点的距离和
                dis[l][r]+=s[mid]-s[k];
            for (int k=mid+1;k<=r;k++)
                dis[l][r]+=s[k]-s[mid];
        }
    memset(f,63,sizeof(f));//=赋INF
    f[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (j>i) {f[i][j]=0;continue;}
            for (int k=j-1;k<i;k++)
                f[i][j]=mmin(f[i][j],f[k][j-1]+dis[k+1][i]);//选择在[k+1,i]中修路价格最小的方案
        }
    printf("%d\n",f[n][m]);
}
