#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int t,n,k,dp[200010][100],res;
int f[200010];
int sum(int x)
{
	int cnt=0;
	while(x)
	{
		if(x%2==1) cnt++;
		x/=2;
	}
	return cnt;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][f[i]]=1;
			for(int j=0;j<=63;j++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j])%MOD;
				dp[i][j&f[i]] = (dp[i][j&f[i]] + dp[i - 1][j])%MOD;
			}
		}
		for(int i=0;i<=63;i++)
		{
			if(sum(i)==k) res=(res+dp[n][i])%MOD;
		}
		printf("%d\n",res);
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j <= 63;j++)
			{
				dp[i][j] = 0;
			}
		}
	}
	return 0;
}