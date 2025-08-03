#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,k,dp[10010][1010],f[10010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int j=1;j<=k;j++)
	{
		dp[0][j]=-0x3f3f3f3f3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=-0x3f3f3f3f3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j]=-0x3f3f3f3f3f3f3f3f;
			if(j<=i) 
			{
				for(int p=1;p<=6;p++)
				{
					if(i-p>=0)
					{
						dp[i][j]=max(dp[i][j],dp[i-p][j-1]+f[i]);	
					}
				}
			}
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	ll maxx=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++) maxx=max(maxx,dp[i][k]);
	cout<<maxx<<endl;
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