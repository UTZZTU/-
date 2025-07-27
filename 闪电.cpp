#include <stdio.h>
int main ()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int a=1;a<=n+1-i;a++)
			{
				printf(" ");
			}
			printf("*");
			printf("\n");
		}
	for(int i=1;i<=n+1;i++)
	{
		printf("*");
	}
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int a=1;a<=n-i;a++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
		
	}
	printf("\n");
	}
	return 0;
}
