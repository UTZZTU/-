#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b[100010],a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>b[i];
	}
	a[1]=b[1];
	for(int i=2;i<n;i++)
	{
		a[i]=b[i-1];
		for(ll j=0;j<30;j++)
		{
			if((b[i]>>j)&1)
			{
				if((a[i]>>j)&1) ;
				else a[i]+=(1<<j);
			}
		}
	}
	a[n]=b[n-1];
	for(int i=1;i<n;i++)
	{
		if((a[i]&a[i+1])!=b[i])
		{
			cout<<-1<<endl;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
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