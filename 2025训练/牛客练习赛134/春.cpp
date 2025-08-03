#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll x,y;
void solve()
{
	cin>>x>>y;
	if(x==1) cout<<10+y;
	else if(x==2) cout<<1000000000+y;
	else cout<<1000000000000000000+y;
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