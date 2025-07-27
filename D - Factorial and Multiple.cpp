#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll k,primes[1000000],cnt,t,maxx,l,r,mid;
map<ll,ll> mp;
bool check(ll x)
{
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		ll ans=0,mb=it->first,t=x;
		while(t>=mb)
		{
			ans+=t/mb;
			t/=mb;
		}
		if(ans<it->second)
		return false;
	}
	return true;
}
int main ()
{
	cin>>k;
	t=k;
	for(ll i=2;i*i<=k;i++)
	{
		if(t%i==0)
		{
			while(t%i==0)
			{
				t/=i;
				mp[i]++;
			}
		}
	}
	if(t>1)
	{
		mp[t]++;
	}
	l=2,r=k;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
}