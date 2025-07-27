#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,q,a[200010],res,sum;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&q);
		res=sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=q)
			{
				sum++;
			}
			else
			{
				if(sum>=k)
				{
					ll x=sum-k+1;
					res+=x*(x+1)/2;
				}
				sum=0;
			}
		}
		if(sum>=k)
		{
			ll x=sum-k+1;
			res+=x*(x+1)/2;
		}
		printf("%lld\n",res);
	}
	return 0;
}