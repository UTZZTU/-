#include <stdio.h>
int main ()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int c[100];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=0;i<n-1;i++)
		{
			for(int a=0;a<n-1-i;a++)
			{
				if(c[a]>c[a+1])
				{
					m=c[a];
					c[a]=c[a+1];
					c[a+1]=m;
				}
			}
		}
		printf("%d %d\n",c[n-1],c[n-2]);
	}
	return 0;
}
