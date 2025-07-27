#include <stdio.h>
int main ()
{
	long long a,n,i;
	a=1;
	scanf("%lld",&n);
	for(i=n-1;i>=1;i--)
	{
		a+=i;a*=2;
	}
	printf("The monkey got %lld peachs in first day.",a);
	return 0;
}
