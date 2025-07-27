#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,dp[100010],a[100010];
string s;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	getchar();
	cin>>s;
	for(int i=2;i<=n;i++)
	{
		if(s[i-1]==s[i-2])
		{
			dp[i]=max(dp[i],dp[i-1]);
		}
		else
		{
			dp[i]=max(dp[i-1],dp[i-2]+a[i-1]+a[i]);
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}