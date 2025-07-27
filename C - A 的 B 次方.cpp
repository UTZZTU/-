#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,m;
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
	cin>>a>>b>>m;
	cout<<fast_power(a,b,m);
	return 0;
}