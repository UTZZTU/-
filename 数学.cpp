#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int INF = 0x3f;
int dp[100010],n,res=1;
signed main ()
{
	memset(dp,INF,sizeof dp);
	dp[1]=1;
	dp[0]=0;
	for(int i=1;i*i<=100000;i++)
	{
		for(int j=i*i;j<=100000;j++)
		{
			dp[j]=min(dp[j],dp[j-i*i]+1);
		}
	}
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
//		cout<<dp[i]<<endl;
		res=res*dp[i]%MOD;
	}
	printf("%lld",res);
	return 0;
}