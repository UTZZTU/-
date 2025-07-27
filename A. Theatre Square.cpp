#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a;
void solve()
{
	cin>>n>>m>>a;
	cout<<((n+a-1)/a)*((m+a-1)/a)<<endl;
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