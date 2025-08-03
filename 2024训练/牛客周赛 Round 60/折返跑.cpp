#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll MOD = 1e9+7;
ll p[1000010],q[1000010],n,m;
ll qmi(ll a,ll b)
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
	cin>>n>>m;
	if(n-2<=0)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<(p[n-2]*q[n-1-m])%MOD*q[m-1]%MOD<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	p[0]=q[0]=1;
	for(ll i=1;i<=1000000;i++)
	{
		p[i]=(p[i-1]*i)%MOD;
		q[i]=(q[i-1]*qmi(i,MOD-2))%MOD;
	}
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}