#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll a[1010],b[1010],n;
int main ()
{
	cin>>n;
	ll res=1,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		res*=a[i];
	}
	for(int i=0;i<n;i++)
	{
		ll M=res/a[i];
		ll t,x;
		exgcd(M,a[i],t,x);
		sum+=b[i]*M*t;
	}
	cout<<(sum%res+res)%res;
	return 0;
}