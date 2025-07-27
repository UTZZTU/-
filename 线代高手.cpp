#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100],b[100],f[100][100],t;
bool check(ll x,ll y)
{
	if(x>n||y>m) return false;
	for(int i=1;i<=n-x+1;i++)
	{
		for(int j=1;j<=m-y+1;j++)
		{
			int p1=i+x-1,p2=j+y-1;
			if(f[p1][p2]-f[i-1][p2]-f[p1][j-1]+f[i-1][j-1]<=t)
			return true;
		}
	}
	return false;
}
bool judge(ll x)
{
	for(ll i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ll p=i,q=x/i;
			if(check(p,q)) return true;
			if(check(q,p)) return true;
		}
	}
	return false;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	cin>>t;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ll k=a[i]*b[j];
			f[i][j]=f[i-1][j]+f[i][j-1]+k-f[i-1][j-1];
		}
	}
	for(ll i=n*m;i>=1;i--)
	{
		if(judge(i))
		{
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}