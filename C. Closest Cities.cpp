#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],m,x,y,pre[100010],post[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=0;
		post[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		if(i==1)
		{
			pre[i+1]=pre[i]+1;
		}
		else
		{
			if(a[i+1]-a[i]<a[i]-a[i-1]) pre[i+1]=pre[i]+1;
			else pre[i+1]=pre[i]+a[i+1]-a[i];
		}
	}
	for(int i=n;i>1;i--)
	{
		if(i==n)
		{
			post[i-1]=post[i]+1;
		}
		else
		{
			if(a[i+1]-a[i]<a[i]-a[i-1]) post[i-1]=post[i]+a[i]-a[i-1];
			else post[i-1]=post[i]+1;
		}
	}
	cin>>m;
	while(m--)
	{
		cin>>x>>y;
		if(x>=y) cout<<post[y]-post[x]<<endl;
		else cout<<pre[y]-pre[x]<<endl;
	}
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}