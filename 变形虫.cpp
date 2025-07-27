#include <stdio.h>
typedef long long ll;
int main ()
{
	ll a,n,i,k;
	scanf("%lld%lld",&a,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(a==k)
		a*=2;
	}
	printf("%lld",a);
	return 0;
}