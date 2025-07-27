#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100010],sum[100010],res;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]=abs(a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<=n;i++)
		{
			res+=n*a[i]+sum[n];
		}
		printf("%lld\n",res);
	}
	return 0;
}