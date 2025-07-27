#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[10000010],dp[10000010],maxx;
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		a[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i-1],0)+a[i];
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
	return 0;
}