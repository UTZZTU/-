#include <stdio.h>
int main ()
{
	int t,n,x,w;
	scanf("%d",&t);
	while(t--)
	{
		w=0;
		scanf("%d",&n);
		int c[10];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		scanf("%d",&x);
		for(int i=0;i<n;i++)
		{
			if(c[i]==x)
			{
				printf("find!\n");
			}
			else w++;
		}
		if(w==n)
		printf("no find!\n");
	}
	return 0;
}
