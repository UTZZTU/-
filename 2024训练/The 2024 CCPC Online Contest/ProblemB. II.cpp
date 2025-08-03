#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD =  998244353;
mt19937_64 mrand(random_device{}()); 
ll n,f[1010],res,pre,inv[1010],p[1010],m[1000100],sum=1;
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=(res*a)%MOD;
		b>>=1;
		a=(a*a)%MOD;
	}
	return res;
}
void solve()
{
	p[0]=inv[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		m[f[i]]++;
	}
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		pre+=f[i];
		res+=f[i]*(ll)i-pre;
		p[i]=(p[i-1]*(ll)i)%MOD;
//		inv[i]=(inv[i-1]*ksm((ll)i,MOD-2))%MOD;
	}
	for(int i=1;i<=1000000;i++)
	{
		if(m[i]>1)
		{
			sum=(sum*p[m[i]])%MOD;
		}
	}
	if(f[1]!=f[n])
	sum=(sum*2ll)%MOD;
	cout<<res<<" "<<sum<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}