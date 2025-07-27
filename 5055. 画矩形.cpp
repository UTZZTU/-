#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll res,n,m,k;
ll dfs(ll x,ll y,ll level)
{
	if(level==k-1)
	{
		cout<<x<<" "<<y;
	    ll sum=0;
	    for(ll i=1;i<=x-2;i++)
	{
		for(ll j=1;j<=y-2;j++)
		{
			sum=(sum+((x-2)-i+1)%mod*((y-2)-j+1)%mod)%mod;
		}
	}
	cout<<" "<<sum<<endl;
	return sum%mod;
	}
	ll sum=0;
	   for(ll i=3;i<=x-2;i++)
	{
		for(ll j=3;j<=y-2;j++)
		{
			sum=(sum+((x-2)-i+1)%mod*((y-2)-j+1)%mod*dfs(i,j,level+1)%mod)%mod;
		}
	}
	return sum%mod;
}
int main ()
{
	cin>>n>>m>>k;
	res=dfs(n,m,0);
	cout<<res%mod;
	return 0;
}