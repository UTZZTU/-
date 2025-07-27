#include <bits/stdc++.h>
using namespace std;
int t,n,f[200010],dp[200010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		dp[n+1]=0;
		dp[n]=1;
		for(int i=n-1;i>=1;i--)
		{
			if(i+f[i]<=n) dp[i]=min(dp[i+1]+1,dp[i+f[i]+1]);
			else dp[i]=dp[i+1]+1;
		}
		printf("%d\n",dp[1]);
	}
	return 0;
}