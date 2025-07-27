#include <stdio.h>
int main ()
{
	int n,k,sum;
	scanf("%d",&n);
	sum=n;
	while(n>=3)
	{
		k=n/3;
		n%=3;
		n+=k;
		sum+=k;
	}
	printf("%d",sum);
	return 0;
}