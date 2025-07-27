#include <stdio.h>
int main ()
{
	int n,m,i,a[100010],q,h,sum=0,zx;
	scanf("%d%d",&n,&m);
	scanf("%d",&q);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d",&h);
		if(q-h>=0)
		{
			a[i]=q-h;
		}
		else
		{
			a[i]=h-q;
		}
		q=h;
	}
	for(i=1;i<=m-1;i++)
	{
		sum+=a[i];
	}
	zx=sum;
	for(i=m;i<=n-1;i++)
	{
		sum=sum+a[i]-a[i-(m-1)];
		if(sum<zx)
		zx=sum;
	}
	printf("%d",zx);
	return 0;
}
