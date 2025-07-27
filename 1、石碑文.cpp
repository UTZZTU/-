#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll qmi(ll a,ll b,ll mod)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll n;
ll C(ll a,ll b)
{
	ll sum=1;
	if(a<b) return (ll)0;
	for(ll i=n-8;i>=n-6;i--)
	{
		sum=sum*i%mod;
	}
	sum=(sum%mod*qmi(6,mod-2,mod)%mod)%mod;
	return sum;
}
int main ()
{
	scanf("%lld",&n);
	if(n-9<0)
	{
		printf("0");
		return 0;
	}
	else if(n-9==0)
	{
		printf("1");
		return 0;
	}
	else
	{
		ll cs=4,pp1=6,pp2=4;
		for(int i=2;i<=n-9;i++)
		{
			cs+=pp1;
			cs%=mod;
			pp1+=pp2;
			pp1%=mod;
			pp2+=1;
			pp2%=mod;
		}
		printf("%lld",(cs%mod*qmi((ll)26,n-9,mod)%mod)%mod);
	}
	return 0;
}