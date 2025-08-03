#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,l,r;
ll cs(ll x)
{
	ll l=1,r=1e9;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(mid*(mid+1)/2>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
void solve()
{
	cin>>n>>l>>r;
	ll l1=cs(l),l2=cs(r);
	if(l2-l1>1)
	{
		cout<<"NO"<<endl;
	}
	else if(l2-l1==1)
	{
		ll p1=l-(l1-1)*l1/2,p2=r-(l2-1)*l2/2;
		if(p2>=p1) cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
		}
	}
	else
	{
		cout<<"YES"<<endl;
	}
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