#include <bits/stdc++.h>
using namespace std;
int dp[100010][10],n,kk,a[100010],pre[10]={-1};
int main ()
{
	scanf("%d%d",&n,&kk);
	memset(dp,1,sizeof(dp));
	for(int i=1;i<=7;i++) dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=7;j++)
		{
			for(int k=1;k<=7;k++)
			{
				if(abs(j-k)<=kk)
				{
					dp[i][k]=min(dp[i][k],dp[i-1][j]+(k!=a[i]));
				}
			}
		}
	}
	int minn=1e9;
	for(int i=1;i<=7;i++)
	{
		minn=min(minn,dp[n][i]);
	}
	printf("%d",minn);
	return 0;
}