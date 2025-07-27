#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 998244353;
ll n,dp[10000000][2];
ll f(ll x)
{
	if(x&1)
	return x/2+1;
	else
	return x/2;
}
int main ()
{
	cin>>n;
	dp[1][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		ll x=i;
		x=f(x);
		if(i&1)
		{
			dp[i][1]=(dp[i-1][0]*x%INF+dp[i-1][1]*((ll)(i+1)-x)%INF)%INF;
			dp[i][0]=(dp[i-1][1]*x%INF+dp[i-1][0]*((ll)(i+1)-x)%INF)%INF;
		}
		else
		{
			dp[i][1]=dp[i-1][1]*(ll)(i+1)%INF;
			dp[i][0]=dp[i-1][0]*(ll)(i+1)%INF;
		}
	}
	cout<<dp[n][1]%INF;
	return 0;
}