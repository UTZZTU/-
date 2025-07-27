#include <stdio.h>
#include <string.h>
int main ()
{
	int t,n,i,k,a[10010],max=0;
	memset(a,0,sizeof(a));
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			a[k]++;
			if(a[k]>max)
			max=a[k];
		}
		if(n%2==0)
	{
		if(max<=n/2)
		printf("Y\n");
		else
		printf("N\n");
	}
	else
	{
		if(max<=n/2+1)
		printf("Y\n");
		else
		printf("N\n");
	}
	}
	return 0;
}