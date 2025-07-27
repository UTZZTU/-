#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,c,s[200010];
bool check(ll x)
{
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=(s[i]+2*x)*(s[i]+2*x);
		if(res>=c) return true;
	}
	return false;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&c);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i]);
		}
		ll l=0,r=1e9+10,mid;
		while(l<r)
		{
			mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}