#include <bits/stdc++.h>
using namespace std;
int t,r,c,w[110][110],dp[110][110];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				scanf("%d",&w[i][j]);
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+w[i][j];
			}
		}
		printf("%d\n",dp[r][c]);
	}
	return 0;
}