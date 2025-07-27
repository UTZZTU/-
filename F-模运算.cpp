#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fast_power(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
ll a,b,p;
int main ()
{
	while(cin>>a>>b>>p)
	{
		if(!a&&!b&&!p)
		break;
		printf("%lld\n",fast_power(a,b,p));
	}
	return 0;
}