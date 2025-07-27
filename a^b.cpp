#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,z;
ll fastpower(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res%p;
}
int main ()
{
	cin>>x>>y>>z;
	cout<<fastpower(x,y,z);
	return 0;
}