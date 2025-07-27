#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,n,a[200010];
ll fun(ll x)
{
	ll t=0;
	t=x*(x-1)/2;
	return t;
}
int main ()
{
	map<ll,ll> mp,mp1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mp[a[i]]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		ll t=fun(it->second);
		mp1[it->first]=t;
		sum+=t;
	}
	for(int i=1;i<=n;i++)
	{
		ll t=sum;
		t-=mp1[a[i]];
		t+=fun(mp[a[i]]-1);
		printf("%lld\n",t);
	}
	return 0;
}