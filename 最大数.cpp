#include <stdio.h>
int main ()
{
	long long int n,max=-999999999;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			if(n>max)
			max=n;
		}
	}
	printf("%lld",max);
	return 0;
}
