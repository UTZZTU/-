#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[1000010],res;
ll get_l(int x)
{
	ll num=0;
	for(int i=x-1;i>=1&&f[i]==0;i--)
	{
		num++;
	}
	return num;
}
ll get_r(int x)
{
	ll num=0;
	for(int i=x+1;i<=n&&f[i]==0;i++)
	{
		num++;
	}
	return num;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
		{
			res++;
			ll l=get_l(i),r=get_r(i);
			res+=l+r;
			res+=l*r;
		}
	}
	cout<<res;
	return 0;
}