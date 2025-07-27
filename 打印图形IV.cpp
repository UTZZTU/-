#include <stdio.h>
int main ()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(j=n;j>=1;j--)
		{
			if(i==j)
			printf("%d",i);
			else
			printf(" ");
		}
		printf(" ");
		for(j=1;j<=i;j++)
		{
			if(i==j)
			printf("%d",i+3);
			else
			printf(" ");
		}
		printf("\n");
	}
	for(k=1;k<=n;k++)
	printf(" ");
	printf("0");
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=1;j--)
		{
			if(i==j)
			printf("%d",i+3);
			else
			printf(" ");
		}
		printf(" ");
		for(j=1;j<=i;j++)
		{
			if(i==j)
			printf("%d",i);
			else
			printf(" ");
		}
		if(i!=n)
		printf("\n");
	}
	return 0;
}