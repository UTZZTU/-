#include <stdio.h>
int main ()
{
	int n,a[100],i,max=0,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>max)
		max=a[i];
	}
	for(j=max;j>=1;j--)
	{
		for(i=0;i<2*n-1;i++)
	{
		if(i%2==0)
		{
			if(a[i/2]>=j)
			printf("*");
			else
			printf(" ");
		}
		else
		printf(" ");
	}
	if(j!=1)
	printf("\n");
	}
	return 0;
}
