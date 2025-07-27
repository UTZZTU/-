#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,dp[10000010];
int main ()
{
	cin>>n>>x>>y;
	dp[1]=x;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+x;
		if(i%2==0)
		{
			ll j=i,res=1;
			while(j%2==0)
			{
				j/=2;
				dp[i]=min(dp[i],dp[j]+res*y);
				res++;
			}
		}
		if((i+1)%2==0)
		{
			ll j=i+1,res=1;
			while(j%2==0)
			{
				j/=2;
				if(j<=i)
				dp[i]=min(dp[i],dp[j]+res*y+x);
				res++;
			}
		}
}
	cout<<dp[n];
	return 0;
}