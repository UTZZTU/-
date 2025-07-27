#include <stdio.h>
#include <math.h>
int main ()
{
	int m,n,t,q;
	int c[20];
	q=2;
	while(q--)
	{
		scanf("%d%d",&m,&n);
		for(int i=0;i<m+n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=0;i<m+n-1;i++)
		{
			for(int a=0;a<m+n-1-i;a++)
			{
				if(c[a]>c[a+1])
				{
					t=c[a];
					c[a]=c[a+1];
					c[a+1]=t;
				}
			}
		}
		for(int i=0;i<m+n-1;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[m+n-1]);
		printf("\n");
	}
	return 0;
}
