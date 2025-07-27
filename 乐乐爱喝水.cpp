#include <stdio.h>
int main ()
{
	int j,t,n,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		printf("1");
		for(j=1;j<=n-1;j++)
		printf("0");
		if(i!=t)
		printf("\n");
	}
	return 0;
}
