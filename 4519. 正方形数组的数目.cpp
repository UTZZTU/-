#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[20];
ll ans;
bool vis[20];
bool check(int x)
{
	int u=(int)sqrt(x);
	return u*u==x;
}
void dfs(int u,int last)
{
	if(u>=n)
	{
		ans++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(i>0&&!vis[i-1]&&a[i]==a[i-1])
		continue;
		if(vis[i])
		continue;
		if(check(last+a[i]))
		{
			vis[i]=true;
			dfs(u+1,a[i]);
			vis[i]=false;
		}
	}
}
int main ()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(i>0&&a[i]==a[i-1])
		continue;
		vis[i]=true;
		dfs(1,a[i]);
		vis[i]=false;
	}
	cout<<ans;
	return 0;
}