#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 9901;
ll a,b,res=1;
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
ll sum(ll x,ll y)
{
	if(!y) return 1;
	if(y%2==0) return (x%MOD * sum(x,y-1)+1)%MOD;
	return (1+qmi(x,y/2+1))%MOD*sum(x,y/2)%MOD;
}
int main ()
{
	cin>>a>>b;
	if(!a)
	{
		cout<<0;
		return 0;
	}
	for(int i=2;i<=a;i++)
	{
		ll s=0;
		while(a%i==0)
		{
			s++;
			a/=i;
		}
		if(s) 
		{
			res=res*sum(i,s*b)%MOD;
		}
	}
	cout<<res;
	return 0;
}