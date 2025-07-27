#include <bits/stdc++.h>
using namespace std;
double dp[510][510];
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-k]+(double)k*1.0/(m-j+k));
			}
		}
	}
	printf("%.9f",dp[n][m]);
	return 0;
}