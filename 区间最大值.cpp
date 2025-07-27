#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,f[500010],k,l,r,a[500010],lg[500010],dp[500010][25],ans;
int main ()
{
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		f[i]=f[i-1]+a[i];
	}
	lg[0]=-1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=a[i];
		lg[i]=lg[i>>1]+1;
	}
	for(int j=1;j<=25;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--)
	{
		scanf("%lld %lld",&l,&r);
		ans=0;
		for(int i=l;i<=r;i++)
		{
		   ll s=lg[i-l+1];
		   ans+=(ll)a[i]*max(dp[l][s],dp[i-(1<<s)+1][s]);
		}
		cout<<ans<<endl;
	}
	return 0;
}