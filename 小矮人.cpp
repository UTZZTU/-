#include <stdio.h>
int main ()
{
	int k,sum=0,i;
	for(i=1;i<=6;i++)
	{
		scanf("%d",&k);
		sum+=k;
	}
	printf("%d",28-sum);
	return 0;
}