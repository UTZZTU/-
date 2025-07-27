#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int dp[1000010][10],n;
signed main ()
{
	scanf("%lld",&n);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(j==9)
			{
				dp[i+1][j]=(dp[i+1][j]+(int)26*dp[i][j])%mod;
			}
			else if(j%3==1)
			{
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
				dp[i+1][j-1]=(dp[i+1][j-1]+(int)24*dp[i][j])%mod;
			}
			else
			{
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
				dp[i+1][j/3*3]=(dp[i+1][j/3*3]+(int)25*dp[i][j])%mod;
			}
		}
	}
	cout<<dp[n][9];
	return 0;
}