#include <bits/stdc++.h>
using namespace std;
int n,a[3],dp[1010];
int main ()
{
	cin>>n>>a[1]>>a[2];
	for(int i=1;i<=2;i++)
	{
		for(int j=a[i];j<=n;j++)
		{
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	cout<<n-dp[n];
	return 0;
}