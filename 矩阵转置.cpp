#include <stdio.h>
int main ()
{
	int t,n;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		scanf("%d",&n);
		int c[10][10],b[10][10];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&c[i][j]);
				b[j][i]=c[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				printf("%d ",b[i][j]);
			}
			printf("%d",b[i][n-1]);
			if(i!=n-1)
			printf("\n");
		}
		if(a!=t)
		printf("\n");
	}
	return 0;
}
