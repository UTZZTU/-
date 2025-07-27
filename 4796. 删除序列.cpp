#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100010],n,k,f[100010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		f[k]++;
	}
	dp[1]=f[1];
	for(int i=2;i<=100000;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+f[i]*i);
	}
	cout<<dp[100000];
	return 0;
}