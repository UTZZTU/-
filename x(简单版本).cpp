#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],res,f[100010],minn=0x3f3f3f3f;
ll get_num(ll x)
{
	ll pos=upper_bound(a+1,a+1+n,x)-a;
	pos--;
	for(ll i=pos;i>=1;i--)
	{
		if(x>=a[i]) x-=a[i];
		if(x==0) break;
	}
	return x;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
//		res+=a[i];
		minn=min(minn,a[i]);
	}
	if(minn>1)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i]=a[i]+f[i-1];
	for(ll i=1;;i++)
	{
		ll num=get_num(f[i]+1);
		if(num)
		{
			printf("%lld",f[i]+1);
			return 0;
		}
	}
	return 0;
}