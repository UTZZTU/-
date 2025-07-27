#include <stdio.h>
int main ()
{
	long long int n,i,a[100010],sum=0;
	scanf("%lld",&n);
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]-a[i-1]>0)
		sum+=a[i]-a[i-1];
	}
	printf("%lld",sum);
	return 0;
}
