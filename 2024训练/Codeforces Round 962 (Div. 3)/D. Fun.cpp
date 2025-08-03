#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,res;
void solve()
{
	res=0;
	cin>>n>>x;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(i*j>n||i+j>x) break;
			ll cnt=n-i*j;
			ll r=cnt/(i+j);
			res+=max(0ll,min(r,x-i-j));
		}
	}
	cout<<res<<endl;
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