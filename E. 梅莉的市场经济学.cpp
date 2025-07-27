#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,k;
bool check(ll x)
{
	return x*(2*x+3)+1>=k;
}
ll find(ll x)
{
	ll l=1,r=2e9,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	return l;
}
int main ()
{
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&k);
		if(k==1)
		{
			printf("0\n");
			continue;
		}
		ll cs=find(k),ws;
		ws=cs*(2*cs+3)+1-k;
		if(ws<=cs)
		{
			printf("%lld\n",-ws);
		}
		else if(ws<=2*cs)
		{
			printf("%lld\n",-(2*cs-ws));
		}
		else if(ws<=3*cs)
		{
			printf("%lld\n",ws-2*cs);
		}
		else if(ws<=4*cs)
		{
			printf("%lld\n",4*cs-ws);
		}
	}
	return 0;
}