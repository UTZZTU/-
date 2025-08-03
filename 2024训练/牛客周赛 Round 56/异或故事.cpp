#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll a;
void solve()
{
	cin>>a;
	for(ll i=1;i<=10000;i++)
	{
		ll j=a^i;
		if(j>=1&&j<=1000000000)
		{
			cout<<i<<" "<<j<<endl;
			return;
		}
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