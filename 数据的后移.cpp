#include <stdio.h>
int main ()
{
	int n,m,i;
	char c[20],b[100];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(i=0;i<n;i++)
		{
			if((i+m%n)>=n)
			b[(i+m%n)%n]=c[i];
			else b[i+m%n]=c[i];
		}
		for(i=0;i<n-1;i++)
		{
			printf("%d ",b[i]);
		}
		printf("%d",b[n-1]);
		printf("\n");
	}
	return 0;
}
