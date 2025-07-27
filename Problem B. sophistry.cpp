#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000100],f[1000100],n,d,m;
int main ()
{
	scanf("%lld%lld%lld",&n,&d,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&f[i]);
	for(int i=n;i>=1;i--)
	{
		if(f[i]>m)
		{
			dp[i]=max(f[i]+dp[i+d+1],dp[i+1]);
		}
		else
		dp[i]=dp[i+1]+f[i];
	}
	cout<<dp[1];
	return 0;
}