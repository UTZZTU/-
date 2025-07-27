#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll n,m,f1[100010],f2[100010],k,cnt;
map<ll,ll> mp1,mp2;
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res;
}
int main ()
{
	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f1[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		mp1[f1[i]]=k;
	}
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&f2[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		mp2[f2[i]]=k;
	}
	cnt=n;
	for(auto it=mp2.begin();it!=mp2.end();it++)
	{
		ll x=it->first,y=it->second;
		mp1[x]-=y;
		if(mp1[x]<0)
		{
			puts("0");
			return 0;
		}
		if(mp1[x]==0) cnt--;
	}
	cout<<qmi((ll)2,cnt);
	return 0;
}
