#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x,y,r,b[210],dp[110],res,cnt;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		res=0;
		cnt=0;
		scanf("%lld%lld%lld%lld",&n,&x,&y,&r);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=2;i++)
		{
			if(i==1)
			{
				for(int j=x;j<=100;j++)
				{
					dp[j]=max(dp[j],dp[j-x]+x);
				}
			}
			else
			{
				for(int j=y;j<=100;j++)
				{
					dp[j]=max(dp[j],dp[j-y]+y);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(res+dp[b[i]]<r)
			{
				res+=dp[b[i]];
				cnt+=(b[i]-dp[b[i]])*(b[i]-dp[b[i]]);
			}
			else
			{
				for(int j=2;j<=b[i];j++)
				{
					if(res+dp[j]>=r)
					{
						res+=dp[j];
						cnt+=(b[i]-dp[j])*(b[i]-dp[j]);
						break;
					}
				}
			}
			if(res>=r)
			{
				for(int j=i+1;j<=n;j++)
				{
					cnt+=b[j]*b[j];
				}
				break;
			}
		}
		if(res>=r) cout<<cnt<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
// 2 1 6 4+1+36=41