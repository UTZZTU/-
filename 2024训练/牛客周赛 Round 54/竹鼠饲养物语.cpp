#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
ll n,m,num,res;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		mp[x]++;
	}
	num=1e9;
	for(ll i=1;;i++)
	{
		if(num==0) break;
		ll minn=min(num,mp[i]);
		num=minn;
		res+=minn;
	}
	cout<<res<<endl;
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