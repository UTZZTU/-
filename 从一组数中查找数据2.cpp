#include <stdio.h>
int main ()
{
	int t,n,x,w;
	int c[10];
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		w=0;
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			scanf("%d",&c[a]);
		}
		scanf("%d",&x);
		for(int a=0;a<n;a++)
		{
			if(c[a]==x)
			{
				printf("find!");
				break;
			}
			else  w++;
		}
		if(w==n)
		printf("no find!");
		if(i!=t)
		printf("\n");
	}
	return 0;
}
