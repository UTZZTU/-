#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200010];
bool check(ll x)
{
	int cnt=0;
	int pre=1,post=1;
	for(post;post<=n;post++)
	{
		if(a[post]-a[pre]>2*x)
		{
			cnt++;
			pre=post;
		}
	}
	cnt++;
	return cnt<=3;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		ll l=0,r=1e9;
		while(l<r)
		{
			ll mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}