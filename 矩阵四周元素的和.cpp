#include <stdio.h>
int main ()
{
	int n,sum=0;
	scanf("%d",&n);
	int c[10][10];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
			if(i==0||i==n-1)
			{
				sum+=c[i][j];
			}
			else if(j==0||j==n-1)
			{
				sum+=c[i][j];
			}
		}
	}
	printf("%d",sum);
	return 0;
}
