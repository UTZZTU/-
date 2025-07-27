#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010],sum,xz;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sum=0;
		xz=a[n];
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]<=xz)
			{
				xz=a[i];
			}
			else
			{
				int p=(a[i]+xz-1)/xz;
				sum+=p-1;
				xz=a[i]/p;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}