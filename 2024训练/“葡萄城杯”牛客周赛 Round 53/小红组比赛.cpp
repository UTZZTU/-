#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,f[110][30],tar,sum,dp[5200],minn=0x3f3f3f3f;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
		}
		sort(f[i]+1,f[i]+1+m);
		sum+=f[i][1];
		for(int j=2;j<=m;j++)
		{
			f[i][j]-=f[i][1];
		}
		f[i][1]=0;
	}
	cin>>tar;
	if(tar<=sum)
	{
		cout<<sum-tar<<endl;
		return;
	}
//	cout<<"yyyyy"<<endl;
//	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=tar-sum+100;j>=0;j--)
		{
			for(int k=1;k<=m;k++)
			{
				if(j>=f[i][k])
				dp[j]=max(dp[j],dp[j-f[i][k]]+f[i][k]);
			}
		}
	}
	for(int i=0;i<=tar-sum+100;i++)
	{
		minn=min(minn,abs(tar-sum-dp[i]));
	}
	cout<<minn<<endl;
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