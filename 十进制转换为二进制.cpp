#include <stdio.h>
int main ()
{
	int n,c[32],j;
	while(scanf("%d",&n)!=EOF)
	{
		j=0;
		if(n==0)
		printf("0\n");
		else
		{
			while(n!=0)
			{
				c[j]=n%2;
				n/=2;
				j++;
			}
			for(j=j-1;j>=0;j--)
			{
				printf("%d",c[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
