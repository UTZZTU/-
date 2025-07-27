#include <stdio.h>
int main ()
{
	int n,i;
	long long t,sum;
	scanf("%d",&n);
	t=1;
	sum=0;
	for(i=1;i<=n;i++)
	{
		t*=i;
		t%=998244353;
		sum+=t;
		sum%=998244353;
	}
	printf("%lld",sum);
	return 0;
}
