#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300010],minn=0x3f3f3f3f,dp1[300010],dp2[300010],f1[300010],f2[300010];
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f1[i]=a[i]+n-i;
		f2[i]=a[i]+i-1;
	}
	dp2[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		dp1[i]=max(f1[i],dp1[i-1]);
	}
	for(int i=n;i>=1;i--)
	{
		dp2[i]=max(f2[i],dp2[i+1]);
	}
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,max(max(dp1[i-1],dp2[i+1]),a[i]));
	}
	printf("%lld",minn);
	return 0;
}
/*
2 7 7 
*/