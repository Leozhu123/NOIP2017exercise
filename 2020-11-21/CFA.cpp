#include<bits/stdc++.h> 
int sum[1005];
int a[1005];
int ss(int m)
{
	long long  k,s=1;
	k=sqrt(m); 
	for(int i=2;i<=k;i++)
	{
		if(m%i==0)
		{
		    s=m/i; return s;	
		}	
			
	}
	return s;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		  	sum[i]=0;
		else
		{
			while(a[i]!=1)
			{
				while(ss(a[i])!=1)
				{
					sum[i]++;
					a[i]=a[i]/ss(a[i]);
				}
				a[i]=a[i]-1;
				sum[i]++;	
			}
		}
	}
	for(int i=1;i<=t;i++)
		printf("%d\n",sum[i]);
	return 0;
}