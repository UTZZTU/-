#include <stdio.h>
int main ()
{
	int t,i;
	long long n;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		printf("No");
		if(i!=t)
		printf("\n");
	}
	return 0;
}
