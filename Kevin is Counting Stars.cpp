#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010],res,k;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		res=0;
		k=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			res+=a[i];
		}
		sort(a+1,a+1+n);
		res-=a[1]+a[n];
		for(int i=1;i<=n;i++)
		{
			if(a[i]<a[n])
			{
				k++;
			}
			else
			break;
		}
		if(k>=2) res++;
		printf("%lld\n",res);
	}
	return 0;
}