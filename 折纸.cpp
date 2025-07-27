#include <stdio.h>
int main ()
{
	long long int n,a,b,c,sum=0,i,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k==1)
		{
			scanf("%lld %lld",&a,&b);
			sum+=2*(a+b);
		}
		else  if(k==2)
		{
			scanf("%lld",&a);
			sum+=4*a;
		}
		else
		{
			scanf("%lld %lld %lld",&a,&b,&c);
			sum+=a+b+c;
		}
	}
	printf("%lld",sum);
	return 0;
}
