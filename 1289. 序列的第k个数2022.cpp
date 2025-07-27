#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 200907;
ll t,a,b,c,k;
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
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
		if(b*b==a*c)
		{
			printf("%lld\n",a*qmi(c/b,k-1,mod)%mod);
		}
		else
		{
			printf("%lld\n",(a+(k-1)%mod*(c-b)%mod)%mod);
		}
	}
	return 0;
}