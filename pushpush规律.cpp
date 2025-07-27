#include <stdio.h>
int main ()
{
	int n,i,a[200010];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	if(n%2==0)
	{
		for(i=n;i>1;i-=2)
		printf("%d ",a[i]);
		for(i=1;i<=n-1;i+=2)
		printf("%d ",a[i]);
	}
	else
	{
		for(i=n;i>=1;i-=2)
		printf("%d ",a[i]);
		for(i=2;i<=n-1;i+=2)
		printf("%d ",a[i]);
	}
	return 0;
}
