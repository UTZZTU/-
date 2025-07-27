#include <stdio.h>
typedef long long ll;
ll fastpower(ll a,ll b,ll p)
{
	ll result=1;
	while(b)
	{
		if(b&1)
		result=result*a%p;
		b>>=1;
		a=a*a%p;
	}
	return result;
}
int main ()
{
	ll a,b,p;
	scanf("%lld %lld %lld",&a,&b,&p);
	printf("%lld^%lld mod %lld=%lld",a,b,p,fastpower(a,b,p));
	return 0;
}