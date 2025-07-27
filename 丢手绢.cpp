#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastpower(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}
ll n,m,k,x,ans,sum,cs;
ll fun(ll a,ll b)
{
	if(a<b)
	swap(a,b);
	ll c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main ()
{
	cin>>n>>m>>k>>x;
	sum=fun(n,m);
	sum=n*m/sum;
	sum/=m;
	cs=fastpower(10,k,sum);
	x=x+cs*m;
	x%=n;
	cout<<x;
	return 0;
}