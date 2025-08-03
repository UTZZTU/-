#include <bits/stdc++.h>
using namespace std;
int dp[200010][3],n;
string s;
/*
r - 0
s - 1
p - 2
*/
void solve()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(s[i]=='R')
			{
				dp[i][2]++;
			}
			else if(s[i]=='S')
			{
				dp[i][0]++;
			}
			else 
			{
				dp[i][1]++;
			}
		}
		else
		{
			if(s[i]=='R')
			{
				dp[i][0]+=max(dp[i-1][1],dp[i-1][2]);
				dp[i][2]++;
				dp[i][2]+=max(dp[i-1][0],dp[i-1][1]);
			}
			else if(s[i]=='S')
			{
				dp[i][1]+=max(dp[i-1][0],dp[i-1][2]);
				dp[i][0]++;
				dp[i][0]+=max(dp[i-1][2],dp[i-1][1]);
			}
			else 
			{
				dp[i][2]+=max(dp[i-1][1],dp[i-1][0]);
				dp[i][1]++;
				dp[i][1]+=max(dp[i-1][0],dp[i-1][2]);
			}
		}
//		cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
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