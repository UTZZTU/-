#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[50];
int f[50][50];
bool judge(int x,int y)
{
	for(int i=x;i<=n;i++)
	{
		for(int j=y;j<=m;j++)
		{
			if(f[i][j]-f[i-x][j]-f[i][j-y]+f[i-x][j-y]==0) return true;
		}
	}
	return false;
}
bool check(int x)
{
	for(int i=1;i<x;i++)
	{
		if(judge(i,x-i)) return true;
	}
	return false;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='1') f[i+1][j+1]=1;
			f[i+1][j+1]+=f[i][j+1]+f[i+1][j]-f[i][j];
		}
	}
	int l=2,r=50;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid))
		{
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l*2<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}