#include <stdio.h>
int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c[1000],t,w=0;
		scanf("%d",&n);
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
					w++;
				}
			}
		}
		printf("%d\n",w);
	}
	return 0;
}
