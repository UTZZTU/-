#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,k,a[200010],res1,res2,pr[200010],inv[200010];
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		{
			res=(res*a)%mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}
ll get(int x,int y){
    return ((pr[x]*inv[y]%mod)*inv[x-y])%mod;
}
void solve()
{
	cin>>n>>k;
	res1=res2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]&1) res1++;
		else res2++;
	}
	if(res1<(k+1ll)/2ll) cout<<0<<endl;
	else
	{
		ll sum=0;
		for(ll i=(k+1ll)/2ll;i<=min(res1,k);i++)
		{
			ll j=k-i;
			if(j>=0&&j<=res2)
			{
				ll pp=get(res1,i)*get(res2,j)%mod;
				sum=(sum+pp)%mod;
			}
		}
		cout<<sum<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	pr[0]=1;
	inv[0]=1;
	for(ll i=1;i<=200000;i++)
	{
		pr[i]=(pr[i-1]*i)%mod;
		inv[i]=(inv[i-1]*qmi(i,mod-2))%mod;
	}
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}