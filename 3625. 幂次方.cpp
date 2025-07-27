#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 233333;
ll x,n;
ll qmi(ll a,ll b,ll mod)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main ()
{
	cin>>x>>n;
	cout<<qmi(x,n,mod);
	return 0;
}