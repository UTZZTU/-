#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[110][110],t,r,c,dp[110][110];
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%lld %lld",&r,&c);
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			scanf("%lld",&f[i][j]);
		}
		dp[1][1]=f[1][1];
		for(int i=2;i<=c;i++)
		dp[1][i]=dp[1][i-1]+f[1][i];
		for(int i=2;i<=r;i++)
		dp[i][1]=dp[i-1][1]+f[i][1];
		for(int i=2;i<=r;i++)
		{
			for(int j=2;j<=c;j++)
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+f[i][j];
		}
		cout<<dp[r][c]<<endl;
	}
	return 0;
}