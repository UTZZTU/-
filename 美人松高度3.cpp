#include <stdio.h>
typedef long long ll;
ll a[1000010];
int main ()
{
	ll n,i,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	scanf("%lld",&k);
	for(i=1;i<=n;i++)
	if(a[i]==k)
	a[i]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=0)
		printf("%lld ",a[i]);
	}
	return 0;
}