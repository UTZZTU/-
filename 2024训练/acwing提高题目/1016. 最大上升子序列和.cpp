#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[1010],dp[1010],maxx;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		dp[i]=f[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f[j]>f[i])
			{
				dp[j]=max(dp[j],dp[i]+f[j]);
//				maxx=max(maxx,dp[j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
	
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}