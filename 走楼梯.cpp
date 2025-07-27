#include <stdio.h>
int main ()
{
	int a[31],n,i;
	a[1]=1;
	a[2]=2;
	scanf("%d",&n);
	for(i=3;i<=30;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
}