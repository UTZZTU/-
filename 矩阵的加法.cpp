#include <stdio.h>
int main ()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)
		break;
		else
		{
			int a[10][10],b[10][10];
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",a[i][j]+b[i][j]);
			}
			if(i!=m-1);
			printf("\n");
		}
		}
	}
	return 0;
}
