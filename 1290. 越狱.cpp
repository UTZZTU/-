#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 100003;
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
ll m,n;
int main ()
{
	scanf("%lld%lld",&m,&n);
	printf("%lld",((fast_power(m,n,MOD)-m*fast_power(m-1,n-1,MOD))%MOD+MOD)%MOD);
	return 0;
}