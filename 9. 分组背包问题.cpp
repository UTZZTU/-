#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,v,s,w[110],vv[110],dp[110];
int main ()
{
	cin>>n>>v;
	while(n--)
	{
		cin>>s;
		for(int i=1;i<=s;i++)
		{
			cin>>vv[i]>>w[i];
		}
		for(int j=v;j>=0;j--)
		{
			for(int k=1;k<=s;k++)
			{
				if(j>=vv[k])
				dp[j]=max(dp[j],dp[j-vv[k]]+w[k]);
			}
		}
	}
	cout<<dp[v];
	return 0;
}