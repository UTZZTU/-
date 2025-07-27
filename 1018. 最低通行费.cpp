#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int n,w[110][110],dp[110][110];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&w[i][j]);
			if(i==1&&j==1)
			{
				dp[i][j]=w[i][j];
			}
			else
			{
				dp[i][j]=INF;
				if(i>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+w[i][j]);
				if(j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]+w[i][j]);
			}
		}
	}
	printf("%d",dp[n][n]);
	return 0;
}