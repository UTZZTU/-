#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[1010][1010],n,a[1010][1010],maxx=-INF;
int main ()
{
	memset(dp,-INF,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==1&&j==1)
			dp[i][j]=a[i][j];
			else
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dp[n][i]>maxx)
		maxx=dp[n][i];
	}
	cout<<maxx;
	return 0;
}