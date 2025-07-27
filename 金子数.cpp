#include <stdio.h>
#include <string.h>
int main ()
{
	long long int n,m,x,i,j,a[105],max=0;
	memset(a,0,sizeof(a));
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&x);
			if(x%8==0)
			a[i]+=x;
		}
		if(a[i]>max)
		max=a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==max)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}
