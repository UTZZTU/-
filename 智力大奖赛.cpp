#include <stdio.h>
int main ()
{
	long long int gs=0,bs=0,n;
	scanf("%lld",&n);
	gs=n*n;
	bs=n*(n+1)/2*3;
	printf("%lld\n%lld",gs,bs);
	return 0;
}
