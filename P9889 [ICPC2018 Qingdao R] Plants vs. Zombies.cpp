#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,a[100010],b[100010];
bool check(int x)
{
	int last=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=ceil(x*1.0/a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=0) continue;
		sum+=(i-last)+(int)2*(b[i]-1);
		if(sum>m) return false;
		last=i;
		b[i+1]-=(b[i]-1);
	}
	return sum<=m;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		int l=0,r=1e18;
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