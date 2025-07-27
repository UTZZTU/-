#include <stdio.h>
#define n 5
int main ()
{
	int c[n],t;
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
				t=c[a];
				c[a]=c[a+1];
				c[a+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",c[i]);
	}
	return 0;
}
