#include <stdio.h>
int main ()
{
	long long int c,n,s;
	scanf("%lld",&c);
	while(c--)
	{
		scanf("%lld",&n);
		s=2*n*n-n+1;
		printf("%d\n",s);
	}
	return 0;
}
