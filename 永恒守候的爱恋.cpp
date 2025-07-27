#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll n,a[200010],b[200010],t=1,ans,tt,a1;
ll fast_power(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[1]++;
		b[a[i]+1]--;
	}
	for(int i=1;i<=200000;i++)
	{
		b[i]+=b[i-1];
	}
	for(int i=1;i<=200000;i++)
	{
		if(!b[i]) break;
		tt=((ll)1+i)*fast_power(i,MOD-2)%MOD;
		t=t*tt%MOD;
		ans=(ans+((ll)1-fast_power(tt,b[i])+MOD)%MOD*(fast_power(((ll)1-tt+MOD)%MOD,MOD-2))%MOD*t%MOD)%MOD;
		t=t*fast_power(tt,b[i]-1)%MOD;
	}
	cout<<ans;
	return 0;
}