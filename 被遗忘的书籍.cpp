#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res%MOD;
}
int dp[200010][3],t,n;
signed main ()
{
	dp[1][0]=24;
	dp[1][1]=1;
	dp[1][2]=1;
	for(int i=2;i<=200000;i++)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=0;
		dp[i][0]=((dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD*24)%MOD;
		dp[i][1]+=(dp[i-1][1]+dp[i-1][0])%MOD;
		dp[i][1]%=MOD;
		if(i>=3)
		{
			dp[i][1]+=(dp[i-2][2]+dp[i-2][0])%MOD;
		}
		else dp[i][1]+=(dp[i-1][2])%MOD;
		dp[i][1]%=MOD;
		dp[i][2]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
//			cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n<3)
		{
			printf("0\n");
			continue;
		}
		int sum=qmi((int)26,n)%MOD;
		
//		cout<<dp[n][0]<<" "<<dp[n][1]<<" "<<dp[n][2]<<endl;
		sum-=dp[n][0];
		sum-=dp[n][1];
		sum-=dp[n][2];
		sum=(sum%MOD+MOD)%MOD;
		printf("%lld\n",sum);
	}
	return 0;
}