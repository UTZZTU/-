#include <bits/stdc++.h>
using namespace std;
#define int long long
int x;
void solve()
{
	cin>>x;
	x=abs(x);
	int ans=ceil((-1+sqrt(1+8.0*x))/2.0);
	int res=ans*(ans+1)/2-x;
	while(res&1)
	{
		res+=++ans;
	}
	cout<<ans<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}