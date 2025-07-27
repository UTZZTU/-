#include <stdio.h>
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int c[10],t;
		c[0]=n;
		for(int i=1;i<10;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=0;i<9;i++)
		{
			for(int a=0;a<9-i;a++)
			{
				if(c[a]>c[a+1])
				{
					t=c[a];
					c[a]=c[a+1];
					c[a+1]=t;
				}
			}
		}
		for(int i=0;i<9;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[9]);
		printf("\n");
	}
	return 0;
}
