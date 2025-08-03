#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n;
bool check(ll x,ll p)
{
	ll res=0;
	if(x%10>=5) res++;
	res+=x/10;
	res+=x/3ll-x/6ll;
	if(x>=15)
	{
		res-=(x-15)/30;
		res--;
	}
	return res>=p;
}
// 15 45 75 105 
void solve()
{
	cin>>n;
	ll l=1,r=1e18;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(check(mid,n)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
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