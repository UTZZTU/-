#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,pre[10010],post[1010],a[1010],maxx;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=post[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[i]) pre[j]=max(pre[j],pre[i]+1);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]>a[i]) post[j]=max(post[j],post[i]+1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,pre[i]+post[i]-1);
	}
	cout<<maxx;
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