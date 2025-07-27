#include <stdio.h>
typedef long long ll;
ll a[1000010];
int main ()
{
	ll n,i,k,sum=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	scanf("%lld",&k);
	for(i=1;i<=n;i++)
	if(a[i]==k)
	sum++;
	printf("%lld",sum);
	return 0;
}