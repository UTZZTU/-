#include <bits/stdc++.h>
using namespace std;
int n,m,v[1010],w[1010],l[1010],h[1010],dp[1010];
int main ()
{
	cin>>n>>m>>v[0]>>w[0];
	for(int i=1;i<=m;i++){
		cin>>l[i]>>h[i]>>v[i]>>w[i];
	}
	for(int i=v[0];i<=n;i++){
		dp[i]=dp[i-v[0]]+w[0];
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=1;j--){
			for(int k=1;k<=l[i]/h[i]&&k*v[i]<=j;k++){
				dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
			}
		}
	}
	cout<<dp[n];
	return 0;
}