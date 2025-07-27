#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll t,n,res,k,maxx;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		map<ll,ll> mp;
		res=1;
		maxx=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			mp[k]++;
			maxx=max(maxx,k);
		}
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(it->first!=maxx)
			{
				res=res*(it->second+1)%mod;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}