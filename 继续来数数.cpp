#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll qmi(ll a,ll b,ll p)
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
ll t,n,k,a[100010],flag,pos1,pos2;
ll C(ll m,ll n)
{
	if(m<n) return (ll)0;
	ll res=1;
	ll minn=min(n,m-n);
	for(ll i=m;i>=m-minn+1;i--)
	{
		res=res*i%mod;
	}
	res%=mod;
	for(ll i=2;i<=minn;i++)
	{
		res=res*qmi(i,mod-2,mod)%mod;
	}
	return res%mod;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		flag=0;
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(mp[a[i]])
			{
				pos1=mp[a[i]];
				pos2=i;
				flag=1;
			}
			else mp[a[i]]=i;
		}
		if(!flag)
		{
			printf("%lld\n",C(n,k)%mod);
		}
		else
		{
			printf("%lld\n",((C(n,k)-C(n-1-(pos2-pos1),k-1))%mod+mod)%mod);
		}
	}
	return 0;
}