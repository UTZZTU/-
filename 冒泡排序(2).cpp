#include <stdio.h>
int main ()
{
	int n,m,t;
	int c[20];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n-1-i;j++)
			{
				if(c[j]>c[j+1])
				{
					t=c[j];
					c[j]=c[j+1];
					c[j+1]=t;
				}
			}
		}
		for(int i=0;i<n-1;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[n-1]);
		printf("\n");
	}
	return 0;
 } 
