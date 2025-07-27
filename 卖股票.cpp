#include <stdio.h>
int main ()
{
	int a[1000100],b[1000100],n,i,max;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	b[1]=a[2]-a[1];
	max=b[1];
	for(i=2;i<n;i++)
	{
		if(b[i-1]<0)
		{
			b[i]=a[i+1]-a[i];
		}
		else
		{
			if(a[i+1]>=a[i])
			b[i]=a[i+1]-a[i]+b[i-1];
			else
			b[i]=b[i-1]-(a[i]-a[i+1]);
		}
		if(b[i]>max)
		max=b[i];
	}
	printf("%d",max);
	return 0;
}