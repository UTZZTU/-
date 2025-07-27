#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h,a[100010],b[100010];
bool check(ll x)
{
	ll res=0,cnt=0;
	for(int i=n;i>=1;i--)
	{
		if(b[i]>=a[n])
		{
			res+=b[i];
			cnt++;
		}
		else break;
		if(cnt>=x) break;
	}
	res+=(x-cnt)*a[n];
	return res>=h;
}
int main ()
{
	scanf("%lld%lld",&n,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ll l=1,r=1e9;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}