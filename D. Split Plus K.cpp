#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,a[200010];
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		int maxx,minn;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]-=k;
			if(i==1)
			{
				maxx=a[i];
				minn=a[i];
			}
			else
			{
				maxx=max(maxx,a[i]);
				minn=min(minn,a[i]);
			}
		}
		if(maxx==minn) puts("0");
		else if(minn<0&&maxx>=0||minn==0&&maxx>0) puts("-1");
		else
		{
			int g=a[1];
			for(int i=2;i<=n;i++) g=__gcd(g,a[i]);
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				sum+=a[i]/g-1;
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}