#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[1000100],dp[1000100],res,minn=0x3f3f3f3f;
multiset<ll> st;
int main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		res+=a[i];
	}
	dp[2]=0x3f3f3f3f;
	for(int i=3;i<=n-2;i++)
	{
		if(i==3)
		{
			dp[i]=a[i];
		}
		else
		{
			st.insert(dp[i-2]);
			if(i-(k+2)-1>=2)
			{
				st.erase(st.lower_bound(dp[i-(k+2)-1]));
			}
			dp[i]=a[i]+*st.begin();
		}
	}
	minn=0x3f3f3f3f;
	for(int i=n-2;i>=n-2-k&&i>=2;i--)
	{
		minn=min(minn,dp[i]);
    }
    if(n==3)
    {
    	cout<<a[2];
    	return 0;
	}
	else if(n==4)
	{
		cout<<a[2]+a[3];
    	return 0;
	}
	else
	{
		cout<<res-minn-a[1]-a[n];
	}
	return 0;
}