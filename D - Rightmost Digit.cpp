#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod = 10;
ll t,n;
ll fast_power(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<fast_power(n,n,Mod)<<endl;
	}
	return 0;
}