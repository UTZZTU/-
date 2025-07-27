#include <bits/stdc++.h>
using namespace std;
int m,n,w[55][55],dp[110][55][55];
int main ()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	for(int k=2;k<=m+n;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int p1=k-i,p2=k-j;
				if(p1>=1&&p1<=n&&p2>=1&&p2<=n)
				{
					int t=w[i][p1];
					if(i!=j) t+=w[j][p2];
					int &x=dp[k][i][j];
					x=max(x,dp[k-1][i-1][j-1]+t);
					x=max(x,dp[k-1][i-1][j]+t);
					x=max(x,dp[k-1][i][j-1]+t);
					x=max(x,dp[k-1][i][j]+t);
				}
			}
		}
	}
	printf("%d",dp[m+n][m][m]);
	return 0;
}