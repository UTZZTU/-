#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[1000010][2],a[1000010],res;
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][1];
		}
		else
		{
			dp[i][0]=dp[i-1][1];
			dp[i][1]=dp[i-1][0]+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		res+=dp[i][0];
	}
	cout<<res;
	return 0;
}