#include <stdio.h>
int main ()
{
	int t,i,n,k,sum=0,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum=0;
		scanf("%d",&n);
		sum+=(n-2)*8;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&k);
			sum+=k;
		}
		printf("%d",sum);
		if(i!=t)
		printf("\n");
	}
	return 0;
}