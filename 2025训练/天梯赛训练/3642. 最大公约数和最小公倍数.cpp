#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}());
int n,m; 
void solve()
{
	cin>>n>>m;
	cout<<__gcd(n,m)<<" "<<n*m/__gcd(n,m)<<endl;
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