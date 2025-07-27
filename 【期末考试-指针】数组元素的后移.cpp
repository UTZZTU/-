#include <stdio.h>
int main ()
{
	int m,n,c[10],*p,i;
	p=c;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
	for(i=n+1;i<m;i++)
	{
		printf("%d ",p[i]);
	}
	printf("%d",p[n]);
	return 0;
}
