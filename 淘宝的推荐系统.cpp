#include <bits/stdc++.h>
using namespace std;
int f[100010],dp[100010],t,n,d;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&d);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		scanf("%d",&f[i]);
		for(int i=1;i<=n;i++)
		{
			int v=f[i];
			dp[v]++;
			for(int j=-d;j<=d;j++)
			{
				int u=v+j;
				if(u>=1&&u<=100000&&dp[u]&&u!=v)
				dp[v]=max(dp[v],dp[u]+1);
			}
		}
		int maxx=0;
		for(int i=1;i<=n;i++)
		maxx=max(maxx,dp[f[i]]);
		printf("%d\n",maxx);
	}
	return 0;
}