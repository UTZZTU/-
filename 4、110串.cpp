#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,k,dp[1010][1010][2],res;
string s;
void solve()
{
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	dp[0][0][0]=1;
	dp[1][0][s[1]-'0']=1;
	dp[1][1][(1-(s[1]-'0'))]=1;
	dp[2][0][s[2]-'0']+=dp[1][0][s[1]-'0'];
	dp[2][1][s[2]-'0']+=dp[1][1][1-(s[1]-'0')];
	dp[2][1][1-(s[2]-'0')]+=dp[1][0][s[1]-'0'];
	dp[2][2][1-(s[2]-'0')]+=dp[1][1][1-(s[1]-'0')];
	cout<<dp[1][1][0]<<" "<<dp[1][1][1]<<endl;
	cout<<dp[2][1][0]<<" "<<dp[2][1][1]<<endl;
	cout<<dp[2][2][0]<<" "<<dp[2][2][1]<<endl;
	cout<<endl;
	for(int i=3;i<=n;i++)
	{
//		if(i>1)
//		dp[i][0][s[i]-'0']=(dp[i][0][s[i]-'0']+dp[i-1][0][s[i-1]])%mod;
////		dp[i][0][s[i]-'0']=(dp[i][0][s[i]-'0']+dp[((i-1)%4+4)%4][0][s[i-1]])%mod;
//		for(int j=1;j<=min(i,k);j++)
//		{
//			dp[i][j][s[i]-'0']=(dp[i][j][s[i]-'0']+dp[i-1][j][])
//		}
		dp[i][0][s[i]-'0']+=dp[i-1][0][s[i-1]-'0'];
		if(s[i]=='1')
		{
			for(int j=1;j<=min(i,k);j++)
			{
				dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][s[i-1]-'0']+dp[i-1][j][1-(s[i-1]-'0')])%mod;
				if(s[i-1]=='1')
				dp[i][j][0]=(dp[i][j][0]+dp[i-1][j-1][0]+dp[i-1][j-1][1]*dp[i-2][j-1][0]%mod)%mod;
				else
				dp[i][j][0]=(dp[i][j][0]+dp[i-1][j-1][0]+dp[i-1][j-1][1]*dp[i-2][j-2][0]%mod)%mod;
				cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
			}
		}
		else
		{
			for(int j=1;j<=min(i,k);j++)
			{
				dp[i][j][1]=(dp[i][j][1]+dp[i-1][j-1][s[i-1]-'0']+dp[i-1][j-1][1-(s[i-1]-'0')])%mod;
				if(s[i-1]=='1')
				dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][0]+dp[i-1][j][1]*dp[i-2][j][0]%mod)%mod;
				else
				dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][0]+dp[i-1][j][1]*dp[i-2][j-1][0]%mod)%mod;
				cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		res=(res+dp[n][i][0]+dp[n][i][1])%mod;
	}
	cout<<res;
}
signed main ()
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