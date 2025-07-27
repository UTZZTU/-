#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000010;
ll n,p,primes[N],cnt;
bool st[N];
void init(ll x)
{
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
ll get(ll x,ll y)
{
	ll res=0;
	while(x) res+=x/y,x/=y;
	return res;
}
ll C(ll a,ll b)
{
	ll res=1;
	for(int i=0;i<cnt;i++)
	{
		ll prime=primes[i];
		ll s=get(a,prime)-get(b,prime)-get(a-b,prime);
		res=res*qmi(prime,s)%p;
	}
	return res;
}
int main ()
{
	cin>>n>>p;
	init(2*n);
	cout<<((C(2*n,n)-C(2*n,n-1))%p+p)%p;
	return 0;
}