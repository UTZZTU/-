#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 5000011;
ll f[100010],n,k,dp[100010];
int main ()
{
	cin>>n>>k;
	f[0]=dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i-k-1<=0)
		f[i]=1;
		else
		f[i]=dp[i-k-1]%MOD;
		dp[i]=(dp[i-1]+f[i])%MOD;
	}
	cout<<dp[n];
	return 0;
}