#include <iostream>
using namespace std;
int n,x,a[55],b[55],dp[10010];
int main ()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=x;j>=0;j--)
		{
			for(int k=1;k<=b[i]&&k*a[i]<=j;k++)
			dp[j]=max(dp[j],dp[j-k*a[i]]+k*a[i]);
		}
	}
	if(dp[x]==x)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}