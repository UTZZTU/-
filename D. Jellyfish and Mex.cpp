#include <bits/stdc++.h>
using namespace std;
int n,a[5010],f[5010],dp[5010];
void solve()
{
	cin>>n;
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=5000) f[a[i]]++;
	}
	int m=0;
	while(f[m]) m++;
	memset(dp,0x3f,sizeof dp);
	dp[m]=0;
	for(int i=m;i;i--)
	{
		for(int j=0;j<i;j++)
		{
			dp[j]=min(dp[j],dp[i]+i*(f[j]-1)+j);
		}
	}
	cout<<dp[0]<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}