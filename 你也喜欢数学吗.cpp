#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll k;
ll qmi(ll a,ll b)
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
	cin>>k;
	k%=mod;
	cout<<k%mod*(k+1)%mod*(k+2)%mod*qmi((ll)6,mod-2)%mod;
	return 0;
}