#include <stdio.h>
int main ()
{
	int n,i,j;
	scanf("%d",&n);
	n=n/2+1;
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=1;j--)
		{
			if(i==j)
			printf("%d",i);
			else
			printf(" ");
		}
		j+=2;
		for(j;j<=i;j++)
		{
			if(i==j)
			printf("%d",i);
			else
			printf(" ");
		}
		printf("\n");
	}
	i-=2;
	for(i;i>=1;i--)
	{
		for(j=n;j>=1;j--)
		{
			if(i==j)
			printf("%d",i);
			else
			printf(" ");
		}
		j+=2;
		for(j;j<=i;j++)
		{
			if(i==j)
			printf("%d",i);
			else
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}