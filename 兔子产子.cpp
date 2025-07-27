#include <stdio.h>
int main ()
{
	int n,a[21],i,j,x;
	a[1]=1;a[2]=1;
	for(i=3;i<=20;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(j=1;j<x;j++)
		{
			printf("%d ",a[j]);
		}
		printf("%d",a[x]);
		if(i!=n)
		printf("\n");
	}
	return 0;
}
