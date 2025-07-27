#include <stdio.h>
int main ()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		k=n-1;
		for(j=1;j<=n;j++)
		{
			if(j>=i)
			{
				printf("%c",'A'+k);
				k--;
			}
			else
			printf(" ");
		}
		j-=2;
		k+=2;
		for(j;j>=i;j--)
		{
			printf("%c",'A'+k);
			k++;
		}
		printf("\n");
	}
	i+=2;
	for(i;i<=n;i++)
	{
		k=n-1;
		for(j=1;j<=n;j++)
		{
			if(j>=i)
			{
				printf("%c",'A'+k);
				k--;
			}
			else
			printf(" ");
		}
		j-=2;
		k+=2;
		for(j;j>=i;j--)
		{
			printf("%c",'A'+k);
			k++;
		}
		printf("\n");
	}
	return 0;
}