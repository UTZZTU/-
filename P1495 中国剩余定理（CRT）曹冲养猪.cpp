#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100],b[100];
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	x=1,y=0;
	else
	{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
int main ()
{
	cin>>n;
	ll res=1,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		res*=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll M=res/a[i];
		ll t,x;
		exgcd(M,a[i],t,x);
		sum+=b[i]*M*t;
	}
	cout<<(sum%res+res)%res;
	return 0;
}