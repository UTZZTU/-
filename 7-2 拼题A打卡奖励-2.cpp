#include <bits/stdc++.h>
using namespace std;
int dp[30010],n,m,k[1010],c[1010],sum,p;
int main ()
{
	memset(dp,0x3f3f3f3f,sizeof dp);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++) cin>>c[i],sum+=c[i];
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=c[i];j--)
		{
			dp[j]=min(dp[j],dp[j-c[i]]+k[i]);
		}
	}
	for(int i=1;i<=sum;i++)
	{
		if(dp[i]<=m) p=i;
	}
	printf("%d",p);
	return 0;
}