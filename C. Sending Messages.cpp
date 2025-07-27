#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,f,a,b,m[200010],dp[200010][2];
void solve()
{
	cin>>n>>f>>a>>b;
	for(int i=1;i<=n;i++) cin>>m[i];
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+(m[i]-m[i-1])*a;
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+b;
	}
	if(dp[n][0]<f||dp[n][1]<f)
	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}