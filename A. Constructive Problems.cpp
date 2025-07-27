#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve()
{
	cin>>n>>m;
	cout<<max(n,m)<<endl;
}
int main ()
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