#include <stdio.h>
int main ()
{
	int n,c[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&c[i]);
	}
	scanf("%d",&n);
	if(n==10)
	{
		for(i=0;i<9;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[9]);
	}
	else
	{
		for(i=10-n;i<10;i++)
	{
		printf("%d ",c[i]);
	}
	for(i=0;i<9-n;i++)
	{
		printf("%d ",c[i]);
	}
	printf("%d",c[9-n]);
	}
	return 0;
}
