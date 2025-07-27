#include <stdio.h>
int main ()
{
	int t,n,pd,x,i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		pd=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if(x==1)
			pd=1;
		}
		if(pd==1)
		printf("HARD");
		else
		printf("EASY");
		if(i!=t)
		printf("\n");
	}
	return 0;
}
