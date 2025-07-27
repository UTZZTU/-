#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,f[200010],dp[200010],maxx;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&f[i]);
		}
		dp[1]=f[1];
		maxx=dp[1];
		for(int i=2;i<=n;i++)
		{
			if(abs(f[i])%2!=abs(f[i-1])%2)
			{
				dp[i]=max((int)0,dp[i-1])+f[i];
			}
			else
			{
				dp[i]=f[i];
			}
			maxx=max(maxx,dp[i]);
		}
		printf("%lld\n",maxx);
	}
	return 0;
}