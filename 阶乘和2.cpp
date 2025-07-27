#include <stdio.h>
int main ()
{
	int i;
	long long t,sum,n;
	scanf("%lld",&n);
	if(n>=3010)
	n=3010;
	t=1;
	sum=0;
	for(i=1;i<=n;i++)
	{
		t*=i;
		t%=494273703;
		sum+=t;
		sum%=494273703;
	}
	printf("%lld",sum);
	
}
