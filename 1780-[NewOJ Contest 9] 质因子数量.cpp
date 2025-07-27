#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll n,f[1000010],k,res,cnt,tt[1000010];
ll qmi(ll x,ll y,ll mod)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		f[k]++;
	}
	for(int i=2;i<=1000000;i++)
	{
		if(tt[i]) continue;
		ll t=0;
		for(int j=i;j<=1000000;j+=i)
		{
			t+=f[j],tt[j]=1;
		}
		if(t)
		{
			res=(res+(qmi((ll)2,n,mod)-qmi((ll)2,n-t,mod))%mod+mod)%mod;
		}
	}
	cout<<res;
	return 0;
}
/*

*/