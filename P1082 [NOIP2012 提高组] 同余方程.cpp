#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main ()
{
	cin>>a>>b;
	ll x,y;
	ll d=exgcd(a,b,x,y);
	ll t=abs(b/d);
	cout<<(x%t+t)%t;
	return 0;
}