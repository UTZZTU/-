#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,res,t;
ll cut(ll x)
{
	ll sum=0;
	while(x!=1)
	{
		sum++;
		x=ceil(x*1.0/2);
	}
	return sum;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld%lld%lld",&a,&b,&c);
		res+=cut(a);
		res+=cut(b);
		res+=cut(c);
		printf("%lld\n",res);
	}
	return 0;
}