#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,c,d,a[200010],l,r,mid;
bool check(ll x)
{
	ll sum=0,tot=0;
	for(int i=n;i>=1&&i>=n-x;i--)
	sum+=a[i];
	tot=d/(x+1)*sum;
	for(int i=n;i>n-d%(x+1)&&i>=1;i--)
	tot+=a[i];
	return tot>=c;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&c,&d);
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		ll tot=0;
		for(int i=n;i>n-d&&i>=1;i--)
		tot+=a[i];
		if(tot>=c)
		printf("Infinity\n");
		else if(a[n]*d<c)
		printf("Impossible\n");
		else
		{
			l=0,r=d;
			while(l<r)
			{
				mid=(l+r+1)/2;
				if(check(mid))
				l=mid;
				else
				r=mid-1;
			}
			printf("%lld\n",l);
		}
	}
	return 0;
}