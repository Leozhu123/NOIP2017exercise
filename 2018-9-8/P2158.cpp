#include<cstdio>
int n;
int phi(int n)
{
    int ans,i,k;
    if(n==1)
        ans=1;
    else
    {
        ans=n;
        k=1;
        for(i=2;n!=1;i+=k)
        {
            if(n%i==0)
            {
                ans/=i;
                ans*=(i-1);
                while(n%i==0) n/=i;
                i=k;
            }
        }
    }
    return ans;
}
int ans;
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        puts("0");
        return 0;
    }
    for(int i=3;i<=n;++i)
        ans+=phi(i-1);
    printf("%d\n",ans*2+3);
    return 0;
}
