#include <bits/stdc++.h>
using namespace std;
int n,a[5010],dp[5010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=min(n,i+a[i]-1);j>=i;j--)
		{
			if(j-a[i]>=0)
			dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
//	for(int i=1;i<=n;i++) cout<<" dp[i]: "<<dp[i]<<endl;
	if(dp[n]>=1000000)
	cout<<-1<<endl;
	else
	cout<<dp[n]<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}