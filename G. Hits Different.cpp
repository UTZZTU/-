#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000010],t,n;
void init()
{
	ll cnt=1;
	dp[1]=1;
	for(int i=2;i<=10000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cnt++;
			if(j==1)
			{
				dp[cnt]=cnt*cnt+dp[cnt-(i-1)];
			}
			else if(j==i)
			{
				dp[cnt]=cnt*cnt+dp[cnt-i];
			}
			else
			{
				dp[cnt]=cnt*cnt+dp[cnt-(i-1)]+dp[cnt-(i-1)-1]-dp[cnt-(i-1)-(i-2)-1];
			}
			if(cnt>=1000000) break;
		}
		if(cnt>=1000000) break;
	}
}
int main ()
{
	init();
	cin>>t;
	while(t--)
	{
		cin>>n;
		printf("%lld\n",dp[n]);
	}
	return 0;
}