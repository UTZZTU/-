#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,h[200010],sum;
bool get(ll x,ll y,ll hh)
{
	ll res=y/3*3+(y-y/3)-(x/3*3+(x-x/3));
	return res>=hh;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		ll l=1,r=1e9;
		while(l<r)
		{
			ll mid=l+r>>1;
			if(get(sum,sum+mid,h[i])) r=mid;
			else l=mid+1;
		}
		sum+=l;
	}
	cout<<sum<<endl;
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