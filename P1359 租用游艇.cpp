#include <iostream>
using namespace std;
int a[210][210],n,dp[210];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,j;
	cin>>n;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			cin>>a[i][j];
		a[j][i]=a[i][j];
		}
		dp[i]=100000000;
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			dp[i]=min(dp[i],a[i][j]+dp[j]);
		}
	}
	cout<<dp[1];
	return 0;
}