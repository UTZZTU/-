#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,dp0[1010][1010],dp1[1010][1010],a[1010],sum; // 净分数表
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		dp0[i][i]=dp1[i][i]=a[i];
	}
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			if(a[l]>=a[r])
			{
				dp0[l][r]=a[l]-dp1[l+1][r];
			}
			else dp0[l][r]=a[r]-dp1[l][r-1];
			dp1[l][r]=max(a[l]-dp0[l+1][r],a[r]-dp0[l][r-1]);
		}
	}
	int res=dp0[1][n];
	cout<<(sum+res)/2<<" "<<(sum-res)/2<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}