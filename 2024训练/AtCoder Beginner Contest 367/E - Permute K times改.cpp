#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll to[200010][65];
ll n,k,a[200010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>to[i][0];
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(ll j=1;j<=61;j++)
	{
		for(ll i=1;i<=n;i++) to[i][j]=to[to[i][j-1]][j-1];
	}
	for(ll i=1;i<=n;i++)
	{
		ll p=i;
		for(ll j=61;j>=0;j--)
		{
			if((k>>j)&1)
			{
				p=to[p][j];
			}
		}
		cout<<a[p]<<" ";
	}
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