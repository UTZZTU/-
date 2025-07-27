#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,x,f[200010];
bool check(int u)
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]<u) res+=u-f[i];
		if(res>x) return false;
	}
	return true;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&f[i]);
		}
		int l=1,r=2e9+10;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%lld\n",l);
	}
	return 0;
}