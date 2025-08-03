#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m,t,dp[200010],a[200010];
void solve()
{
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	if(t<n)
	{
		cout<<0<<endl;
		return;
	}
	t-=n;
	for(int i=0;i<=t;i++)
	{
		dp[i]=0;
	}
	sort(a+1,a+1+m);
	vector<int> vec;
	for(int i=2;i<=m;i++)
	{
		vec.push_back(2*(a[i]-a[i-1]));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		if(i>0&&vec[i]==vec[i-1]) continue;
		for(int j=vec[i];j<=t;j++)
		{
			dp[j]=max(dp[j],dp[j-vec[i]]+vec[i]);
		}
	}
	cout<<n+dp[t]<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}