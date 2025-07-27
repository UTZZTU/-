#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],b[200010],n,dp[200010][3];
string u;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		if(u=="AA")
		b[i]=0;
		else if(u=="Aa")
		b[i]=1;
		else b[i]=2;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			dp[i][1]=dp[i-1][1];
			dp[i][2]=dp[i-1][2];
			dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i];
		}
		else if(b[i]==1)
		{
			dp[i][0]=dp[i-1][0];
			dp[i][2]=dp[i-1][2];
			dp[i][1]=max(dp[i-1][1],max(dp[i-1][0],dp[i-1][2]))+a[i];
		}
		else
		{
			dp[i][1]=dp[i-1][1];
			dp[i][0]=dp[i-1][0];
			dp[i][2]=max(dp[i-1][2],dp[i-1][1])+a[i];
		}
	}
	cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
	return 0;
}