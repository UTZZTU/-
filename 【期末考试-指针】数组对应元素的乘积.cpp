#include <stdio.h>
int main ()
{
	int n,*p,c[20],w[20],i;
	p=w;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(i=0;i<n;i++)
	{
		p[i]=c[i]*c[n-1-i];
	}
	for(i=0;i<n-1;i++)
	{
		printf("%d ",w[i]);
	}
	printf("%d",w[n-1]);
	return 0;
}
