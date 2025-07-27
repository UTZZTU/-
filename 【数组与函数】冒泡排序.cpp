#include <stdio.h>
int fun(int *p,int n)
{
	int m;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				m=p[j];
				p[j]=p[j+1];
				p[j+1]=m;
			}
		}
	}
}
int main ()
{
	int n,c[20],*p;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		p=c;
		fun(p,n);
		for(int i=0;i<n-1;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[n-1]);
		printf("\n");
	}
	return 0;
}
