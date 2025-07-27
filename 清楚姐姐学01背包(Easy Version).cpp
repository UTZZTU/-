#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,w[110],v[110],f[110],vmaxx,dp[110];
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	vmaxx=f[m];
	for(int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++)
		{
			if(j==i)
			continue;
			for(int k=m;k>=w[j];k--)
			{
				dp[k]=max(dp[k],dp[k-w[j]]+v[j]);
			}
		}
		if(dp[m]<vmaxx)
		cout<<0<<endl;
		else
		{
			memset(dp,0,sizeof(dp));
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				continue;
				for(int k=m-w[i];k>=w[j];k--)
				{
					dp[k]=max(dp[k],dp[k-w[j]]+v[j]);
				}
			}
			cout<<(vmaxx-dp[m-w[i]]-v[i]+1)<<endl;
		}
	}
	return 0;
}