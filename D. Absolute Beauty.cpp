#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010],b[200010],res,maxx,minn;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		maxx=0;
		minn=0x3f3f3f3f;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			if(a[i]>b[i]) swap(a[i],b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			res+=abs(a[i]-b[i]);
			maxx=max(maxx,a[i]);
			minn=min(minn,b[i]);
		}
		if(maxx>minn) res+=2*(maxx-minn);
		printf("%lld\n",res);
	}
	return 0;
}