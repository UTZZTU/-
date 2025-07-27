#include <stdio.h>
int main ()
{
	int n,a,i;
	scanf("%d%d",&n,&a);
	for(i=1;i<=n;i++)
	{
		a-=1;
		a*=2;
	}
	printf("%d",a);
	return 0;
}