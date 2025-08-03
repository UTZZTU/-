#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,a;
void solve()
{
	cin>>n>>t>>a;
	if(t>=(n+1)/2||a>=(n+1)/2) cout<<"Yes";
	else cout<<"No";
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