#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,k,a[200010],cnt,primes[200010],res=1,pos;
bool st[200010];
map<ll,ll> mp;
ll qmi(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int x)
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
int main ()
{
	init(200000);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(!st[a[i]])
		{
			mp[a[i]]++;
			pos++;
		}
		else
		{
			for(int j=2;j*j<=a[i];j++)
			{
				if(a[i]%j==0)
				{
					ll pp=0;
					while(a[i]%j==0)
					{
						pp++;
						a[i]/=j;
					}
					mp[j]+=pp;
					pos+=pp;
					if(!st[a[i]])
					{
						mp[a[i]]++;
						pos++;
						break;
					}
				}
			}
		}
	}
	ll pp=0;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		ll fi=it->first,se=it->second;
		if(pp+se>pos-k)
		{
			res=res*qmi(fi,max((ll)0,pos-k-pp))%mod;
			break;
		}
		else
		{
			pp+=se;
			res=res*qmi(fi,se)%mod;
		}
	}
	cout<<res;
	return 0;
}