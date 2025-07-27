#include <bits/stdc++.h>
using namespace std;
int n,f[2010],c[2020],len,dp[2010][1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=2*n;i++) cin>>c[i];
	for(int i=1;i<=2*n;i++)
	{
		int j=i+1;
		while(j<=2*n&&c[j]<c[i]) j++;
		j--;
		f[++len]=j-i+1;
		i=j;
	}
	for(int i=1;i<=len;i++)
	{
		for(int j=n;j>=f[i];j--)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-f[i]]+f[i]);
		}
	}
	if(dp[len][n]!=n)
	{
		puts("-1");
		return;
	}
	vector<int> a,b;
	map<int,bool> mp;
	int k=n;
	for(int i=len;i>=1;i--)
	{
		if(dp[i][k]>dp[i-1][k])
		{
			mp[i]=true;
			k-=f[i];
		}
	}
	int l=0,r=0;
	for(int i=1;i<=len;i++)
	{
		l++,r+=f[i];
		if(mp[i])
		{
			for(int j=l;j<=r;j++) a.push_back(c[j]);
		}
		else
		{
			for(int j=l;j<=r;j++) b.push_back(c[j]);
		}
		l--;
		l+=f[i];
	}
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<b.size();i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}