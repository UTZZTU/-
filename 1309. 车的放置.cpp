#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 100003;
const int N = 2010;
ll fact[N],infact[N],a,b,c,d,k,res;
ll fast_power(ll a, ll b)
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
ll C(int a,int b)
{
	if(b>a) return 0;
	return fact[a]*infact[a-b]%MOD*infact[b]%MOD;
}
ll P(int a,int b)
{
	if(b>a) return 0;
	return fact[a]*infact[a-b]%MOD;
}
int main ()
{
	cin>>a>>b>>c>>d>>k;
	fact[0]=infact[0]=1;
	for(int i=1;i<=2000;i++)
	{
		fact[i]=fact[i-1]*i%MOD;
		infact[i]=fast_power(fact[i],MOD-2);
	}
	for(int i=0;i<=k;i++)
	{
		res=(res+(C(b,i)*P(a,i)%MOD*C(d,k-i)*P(a+c-i,k-i))%MOD)%MOD;
	}
	cout<<res%MOD;
	return 0;
}