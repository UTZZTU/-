#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,res;
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res%mod;
}
int main ()
{
	cin>>n;//(n*n-(4*n-4))%mod*
	res=(((4*n-4+1+n*n)%mod*((n*n-(4*n-4))%mod)%mod)*qmi((ll)2,mod-2)%mod)%mod*(ll)4%mod;
//	cout<<res<<endl;
	res=(res+(((5+4*n-4)%mod*((4*n-4-4)%mod)%mod)*qmi((ll)2,mod-2)%mod)%mod*(ll)3%mod)%mod;
//	cout<<res<<endl;
	res=(res+20)%mod;
	cout<<res%mod;
	return 0;
}