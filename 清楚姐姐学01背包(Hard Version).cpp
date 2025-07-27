#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,w[5010],v[5010],f[5010][5010],dp[5010][5010],maxx;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	for (int i=1; i<=n; i++){
		for (int j=m; j>=1; j--){
			if (j>=w[i]) f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);		
				else f[i][j]=f[i-1][j];		
		}
	}
	for (int i=n; i>=1; i--){
		for (int j=m; j>=1; j--){
			if (j>=w[i]) dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);		
				else dp[i][j]=dp[i+1][j];		
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxx=0;
		for(int j=0;j<=m;j++)
		{
			maxx=max(maxx,f[i-1][j]+dp[i+1][m-j]);
		}
		if(maxx<f[n][m])
		cout<<0<<endl;
		else
		{
			maxx=0;
			for(int j=0;j<=m-w[i];j++)
			{
				maxx=max(maxx,f[i-1][j]+dp[i+1][m-w[i]-j]);
			}
			maxx+=v[i];
			cout<<(f[n][m]+1-maxx)<<endl;
		}
	}
	return 0;
}