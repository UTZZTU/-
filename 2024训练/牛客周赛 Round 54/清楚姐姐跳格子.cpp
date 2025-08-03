#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1010],dis[1010];
void bfs()
{
	queue<ll> q;
	q.push(1ll);
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		for(ll i=1;i*i<=a[u]&&(u+i<=n||u-i>=1);i++)
		{
			if(a[u]%i==0)
			{
				ll j=a[u]/i;
				if(u+i<=n&&dis[u+i]>dis[u]+1)
				{
					dis[u+i]=dis[u]+1;
					q.push(u+i);
				}
				if(u-i>=1&&dis[u-i]>dis[u]+1)
				{
					dis[u-i]=dis[u]+1;
					q.push(u-i);
				}
				if(u+j<=n&&dis[u+j]>dis[u]+1)
				{
					dis[u+j]=dis[u]+1;
					q.push(u+j);
				}
				if(u-j>=1&&dis[u-j]>dis[u]+1)
				{
					dis[u-j]=dis[u]+1;
					q.push(u-j);
				}
			}
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dis[i]=0x3f3f3f3f;
	}
	dis[1]=0;
	bfs();
	cout<<dis[n];
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