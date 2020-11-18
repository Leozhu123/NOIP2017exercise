#include <bits/stdc++.h>
#define N 300005
using namespace std;
#define rep(i,x,y) for (register int i=x;i<=y;++i)
#define per(i,x,y) for (int i=x;i>=y;i--)
#define quicker ios::sync_with_stdio(false);
#define first fi
#define second sec
typedef long double ld;
typedef long long ll;
const long long INF=2147483647;
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9')
	{
		if(c=='-') flag=1;
		c=getchar();
	}
    while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
    return flag?-x:x;
}
ll max(ll x,ll y)
{
	if (x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

ll min(ll x,ll y)
{
	if (x<y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int q,n,a[300003],o[300003];
int main()
{
	q=read();
	while(q--)
	{
		n=read();
		rep(i,1,n) a[i]=read();
		rep(i,1,n) o[i]=read();
		o[n+1]=-1919810;
		int z;
		z=1;
		rep(i,1,n)
		{
			if(o[i]>o[i+1]){sort(a+z,a+i+1);z=i+1;}
		}
		bool g;
		g=true;
		rep(i,1,n)
		{
			if(a[i]!=o[i]){g=false;puts("NO");break;}
		}
		if(g){puts("YES");}
	}
	return 0;
}
