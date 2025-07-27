#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100010],n,res,pos,f[100010];
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		dp[i]=max((ll)0,dp[i-1])+f[i];
		if(i==1)
		{
			res=dp[i];
			pos=1;
		}
		else
		{
			if(dp[i]>res)
			{
				res=dp[i];
				pos=i;
			}
		}
	}
	printf("%lld\n",res);
	ll i,ans=0;
	for(i=pos;i>=1;i--)
	{
		ans+=f[i];
		if(ans==res)
		{
			printf("%lld,%lld",i,pos);
			return 0;
		}
	}
	return 0;
}