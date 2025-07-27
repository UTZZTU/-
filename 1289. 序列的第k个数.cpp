#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 200907;
ll fast_power(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
ll t,a,b,c,k;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
		if(b-a==c-b)
		{
			printf("%lld\n",(a+(k-1)%MOD*(b-a)%MOD)%MOD);
		}
		else
		{
			printf("%lld\n",a*fast_power(b/a,k-1,MOD)%MOD);
		}
	}
	return 0;
}