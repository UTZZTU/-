#include <stdio.h>
int main ()
{
	int n,a[10][10];
	a[0][0]=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("1\n");
		for(int i=1;i<n;i++)
		{
			a[i][0]=1;
			a[i][i]=1;
			printf("1 ");
			for(int c=1;c<=i-1;c++)
			{
				a[i][c]=a[i-1][c-1]+a[i-1][c];
				printf("%d ",a[i][c]);
			}
		
			printf("1");
			printf("\n");
		}
	}
	return 0;
}
