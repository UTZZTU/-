#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll n,a[100010],dp[100010][10],res;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=10;
	}
	dp[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(j*a[i]%10==6)
			{
				res+=(dp[i-1][j]*qmi(2ll,n-i))%mod;
				res%=mod;
			}
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
			dp[i][j*a[i]%10]+=dp[i-1][j];
			dp[i][j*a[i]%10]%=mod;
		}
	}
	cout<<res<<endl;
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