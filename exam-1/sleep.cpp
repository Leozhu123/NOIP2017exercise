#include <cstdio>
int main()
{
	int Input,Answer;
	scanf("%d",&Input);
	Answer=Input/2;
	if(Input%2==1) printf("%d\n",Answer);
	else if(Answer%2==0) printf("%d\n",Answer-1);
		else printf("%d\n",Answer-2);
	return 0;
}