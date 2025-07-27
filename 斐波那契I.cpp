#include <stdio.h>
int main ()
{
	long long int a[100100];
	int n,i;
	a[1]=2;
	a[2]=3;
	a[3]=5;
	for(i=4;i<=100000;i++)
	{
		a[i]=a[i-1]+a[i-2]-a[i-3];
	}
	scanf("%d",&n);
	printf("%lld",a[n]);
	return 0;
}
