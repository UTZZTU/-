#include <bits/stdc++.h>
using namespace std;
int n,a[300010],b[300010],f[300010],dp[300010];
bool check(int x)
{
	int res=0,maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) res++;
	}
	if(res>=n/2+1) return true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x)
		{
			if(b[i]>=x) f[i]=0;
			else f[i]=-1;
		}
		else
		{
			if(b[i]>=x) f[i]=1;
			else f[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(0,dp[i-1])+f[i];
		maxx=max(maxx,dp[i]);
	}
	return maxx+res>=n/2+1;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	int l=1,r=1e9;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}