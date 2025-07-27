#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll primes[10000010],cnt,n,tt[10000010],flag;
bool st[10000010];
void init(ll x)
{
	st[1]=true;
	for(ll i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(ll j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
void solve(ll x)
{
	for(ll i=0;i<cnt&&primes[i]<=x;i++)
	{
		ll t=x;
		while(t)
		{
			tt[primes[i]]+=t/primes[i];
			t/=primes[i];
		}
	}
}
int main ()
{
	scanf("%lld",&n);
	init(n);
	for(ll i=1;i<=n;i++)
	{
		solve(i);
	}
//	printf("%lld\n",primes[cnt-1]);
	printf("f(%lld)=",n);
	for(int i=0;i<cnt;i++)
	{
//		printf("%d %d\n",primes[i],tt[primes[i]]);
		if(tt[primes[i]])
		{
			if(flag) printf("*");
			if(tt[primes[i]]==1) printf("%lld",primes[i]);
			else printf("%lld^%lld",primes[i],tt[primes[i]]);
			flag=1;
		}
	}
	return 0;
}