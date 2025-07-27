#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
void solve()
{
	cin>>a>>b;
	if(b%a==0)
	{
		cout<<b*(b/a)<<endl;
	}
	else
	{
		int gcds=__gcd(a,b);
		int x=(a/gcds)*b;
		cout<<x<<endl;
	}
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}