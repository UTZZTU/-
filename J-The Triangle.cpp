#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[101][101],n,a[101][101],maxx=-INF;
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
	maxx=-INF;
	memset(dp,-INF,sizeof(dp));
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
	cout<<maxx<<endl;
	}
	return 0;
}