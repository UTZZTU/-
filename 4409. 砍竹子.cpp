#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(fast)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define PI pair<ll,ll>
priority_queue<PI> p;
ll n,h,res;
int main ()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&h);
		if(h!=1)
		p.push({h,i});
	}
	while(!p.empty())
	{
		ll f=p.top().fi,s=p.top().se;
		p.pop();
		ll t=sqrtl(f/2+1);
		if(t!=1) p.push({t,s});
		while(!p.empty()&&p.top().fi==f&&p.top().se==s-1)
		{
			s--;
			p.pop();
			if(t!=1) p.push({t,s});
		}
		res++;
	}
	printf("%lld\n",res);
	return 0;
}