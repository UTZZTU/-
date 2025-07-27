#include <stdio.h>
int main ()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	while(n>a)
	{
		n-=a;
		a+=b;
	}
	printf("%d",n);
	return 0;
}