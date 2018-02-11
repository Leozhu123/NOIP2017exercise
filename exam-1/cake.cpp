#include <cstdio>
#include <algorithm>
using namespace std;
int Price[10005],Best[10005],Total;
int main()
{
	scanf("%d",&Total);
	for(int i=1;i<=Total;i++) scanf("%d",&Price[i]);
	Best[0]=0;
	for(int i=1;i<=Total;i++)
	{
		int Temp=-1;
		for(int j=1;j<=i;j++) Temp=max(Temp,Price[j]+Best[i-j]);
		Best[i]=Temp;
	}
	printf("%d\n",Best[Total]);
	return 0;
}