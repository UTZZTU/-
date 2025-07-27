#include <stdio.h>
int main ()
{
	long long m,n,i,t;
	scanf("%lld %lld",&m,&n);
	t=1;
	for(i=1;i<=n;i++)
	{
		t*=m;
		t%=1000;
	}
	if(t>=100)
	{
		printf("%lld",t);
	}
	else if(t<100&&t>=10)
	{
		printf("0");
		printf("%lld",t);
	}
	else if(t<10)
	{
		printf("00");
		printf("%lld",t);
	}
	return 0;
}
