#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int dp[25],n;
void solve()
{
	cin>>n;
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]+=dp[i-1];
		if(i>=1) dp[i]+=dp[i-2];
		if(i>=2) dp[i]+=dp[i-3];
	}
	cout<<dp[n];
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