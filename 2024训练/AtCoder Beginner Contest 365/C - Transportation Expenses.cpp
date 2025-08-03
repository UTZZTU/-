#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],sum;
bool check(ll x)
{
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=min(a[i],x);
		if(res>m) return false;
	}
	return res<=m;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<=m)
	{
		cout<<"infinite";
		return;
	}
	ll l=0,r=1e10;
	while(l<r)
	{
		ll mid=l+r+1ll>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
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