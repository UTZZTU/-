#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000003;
ll n,l,r,t;
ll qmi(ll a,ll b)
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
ll C(ll a,ll b)
{
	if(a<b) return 0;
	ll up=1,down=1;
	for(int i=a,j=1;j<=b;i--,j++)
	{
		up=up*i%MOD;
		down=down*j%MOD;
	}
	return up*qmi(down,MOD-2)%MOD;
}
ll Lucas(ll x,ll y)
{
	if(x<MOD&&y<MOD) return C(x,y);
	return Lucas(x/MOD,y/MOD)*C(x%MOD,y%MOD)%MOD;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		cout<<((Lucas(r-l+n+1,r-l+1)-1)%MOD+MOD)%MOD<<endl;
	}
	return 0;
}