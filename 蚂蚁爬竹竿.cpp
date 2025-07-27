#include <stdio.h>
int main ()
{
	long long l,time=0,c;
	int n,i;
	scanf("%d",&n);
	scanf("%lld",&l);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&c);
		if(c>l-c)
		c=l-c;
		if(c>time)
		time=c;
	}
	printf("%lld",time);
	return 0;
}
