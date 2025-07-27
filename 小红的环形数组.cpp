#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll res,n,a[200010];
ll qmi(ll a,ll b)
{
	ll cnt=1;
	while(b)
	{
		if(b&1) cnt=cnt*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return cnt;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		res=(res+(n-i)%mod*(n-i+1)%mod*qmi((ll)2,mod-2)%mod*a[i]%mod)%mod;
		res=(res+((ll)i-1)%mod*(ll)i%mod*qmi((ll)2,mod-2)%mod*a[i]%mod)%mod;
		cout<<res<<endl;
	}
	res=(res-(n-2))%mod
	cout<<(res%mod+mod)%mod;
	return 0;
}