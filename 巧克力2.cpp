#include <stdio.h>
int main ()
{
	int a[30],n,i;
	a[1]=1;
	a[2]=2;
	for(i=3;i<25;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	scanf("%d",&n);
	printf("%d",a[n]);
	return 0;
}
