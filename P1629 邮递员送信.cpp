#include <bits/stdc++.h>
using namespace std;
const int INF = 1234567890;
int dp[1010][1010];
int n,m;
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k||dp[i][k]==INF)
			continue;
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		dp[u][v]=min(dp[u][v],w);
	}
	floyd();
	int tot=0;
	for(int i=2;i<=n;i++)
	{
		tot+=dp[1][i]+dp[i][1];
	}
	cout<<tot;
	return 0;
}