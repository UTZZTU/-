#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,judge;
ll sum(ll x,ll y)
{
	__int128 res=1,k=1;
	for(int i=1;i<=y;i++)
	{
	    k*=x;
		res+=k;
		if(res>=2e18) return 2e18;
	}
	return (ll)res;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		judge=0;
		for(ll i=2;i<=64;i++)
		{
			ll l=2,r=1e9;
			while(l<r)
			{
				ll mid=l+r>>1;
				ll t=sum(mid,i);
				if(t>=n) r=mid;
				else l=mid+1;
			}
			if(sum(l,i)==n) judge=1;
		}
		if(judge) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}